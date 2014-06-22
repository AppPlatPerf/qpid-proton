package com.example.examplesendreceive;
import java.util.UUID;

import org.apache.qpid.proton.amqp.messaging.AmqpValue;
import org.apache.qpid.proton.amqp.messaging.Properties;
import org.apache.qpid.proton.message.Message;
import org.apache.qpid.proton.message.jni.JNIMessageFactory;
import org.apache.qpid.proton.messenger.Messenger;
import org.apache.qpid.proton.messenger.MessengerException;
import org.apache.qpid.proton.messenger.Tracker;
import org.apache.qpid.proton.messenger.jni.JNIMessengerFactory;

import android.util.Log;

public class UsingSwig {

	
	/*
	
	This class is filled with static methods that demonstrate what using the
	proton-c swig bindings entails. The methods serve simple core functionalities such as send
	and receive.
	
	In order to start using these methods one should change the address variable
	in the method they want to use.	
	
	 */
	
	
	private UsingSwig() {
	}
	
	public static void send() {
		JNIMessengerFactory factory = new JNIMessengerFactory();
		JNIMessageFactory msgFact = new JNIMessageFactory();
		String address = "";
		
		Messenger msgr = factory.createMessenger();
		
		try{
			//The messenger should be started before sending or receiving messages.
			Log.v("my-tag","starting the messenger.");
			msgr.start();
			//Windows are an AMQP concept that help distinguish how many messages an
			//endpoint can send/receive. In regard to the outgoing window, this is how many
			//we can send.
			Log.v("my-tag","setting outgoing window.");
			msgr.setOutgoingWindow(1);
			//Use the message factory to create a message. Messages should only
			//be constructed through JNIMessageFactories.
			Log.v("my-tag","creating a message.");
			Message msg = msgFact.createMessage();
			Log.v("my-tag","setting the message address to : "+address+".");
			msg.setAddress(address);
			//This is how the body of a message is set to a string.
			Log.v("my-tag","setting the body to 'Hello world'.");
			msg.setBody(new AmqpValue("Hello world"));
			//Put the message on the outgoing queue, where it can be sent off.
			Log.v("my-tag","putting the message.");
			msgr.put(msg);
			//Getting an outgoing tracker from the messenger returns the tracker
			//for the message used in the last put call.
			//With this tracker we can tell if the message was accepted,rejected, or left unknown.
			Log.v("my-tag","getting outgoing tracker.");
			Tracker tracker = msgr.outgoingTracker();
			//Send the message
			Log.v("my-tag","sending the message.");
			msgr.send();
			//Check the status of the message.
			Log.v("my-tag","send status is "+msgr.getStatus(tracker)+".");
			//Stop the messenger. It should be started before using it again.
			Log.v("my-tag","stopping the messenger.");			
			msgr.stop();
			
			
		}
		catch(Exception e) {
			e.printStackTrace();
		}
	}
	
	public static String receive() {
		JNIMessengerFactory factory = new JNIMessengerFactory();
		String address = "";
		
		Messenger msgr = factory.createMessenger();
		
		try{
			//When the messenger subscribes to an address it is declaring
			//What address it will receive messages from.
			Log.v("my-tag","subscribing to address: "+address);
			msgr.subscribe(address);
			//The messenger should be started before use.
			Log.v("my-tag","starting the messenger.");
			msgr.start();
			//Before receiving a message, the messenger should set it's incoming
			//window to a value greater than 0.
			//This tells the remote messenger that we have the capacity to
			//receive messages.
			Log.v("my-tag","setting incoming window.");
			msgr.setIncomingWindow(1);
			//Setting the timeout for the recv call. After 3 seconds without 
			//receiving a message the messenger will time out.
			Log.v("my-tag","setting the messenger timeout to 3 seconds.");
			msgr.setTimeout(3000);
			//This is the recv call to get a message from the remote address.
			Log.v("my-tag","Calling msgr.recv()");
			msgr.recv(1);
			//When a message is received it is added to the incoming queue.
			//From there it must be retrieved with a get() call.
			//In this case msgr.get() returns the first message on the incoming queue.
			Log.v("my-tag","Getting the message from incoming queue");
			Message messageReceived = msgr.get();
			//The call to incomingTracker returns the tracker for the last message
			//We got off the incoming queue.
			//The incoming tracker is what we use to accept the message
			//That we take off of the incoming queue.
			//We need to accept it so the remote messenger knows we successfully received
			//the message.
			Log.v("my-tag","Getting incoming tracker.");	
			Tracker incTracker = msgr.incomingTracker();
			msgr.accept(incTracker, Messenger.CUMULATIVE);
			//Each property can be accessed independently but Properties.toString
			//Is an easy way to see all the properties values with one call.
			Properties props = messageReceived.getProperties();
			Log.v("my-tag","Props tostring: "+props.toString());
			//The messenger should be stopped when no longer in use.
			Log.v("my-tag","stopping the messenger.");			
			msgr.stop();
			//This is my method of getting the string from the message body.
			Log.v("my-tag","returning the message body.");
			return (String)((AmqpValue)(messageReceived.getBody())).getValue();
		}
		catch(Exception e) {
			e.printStackTrace();
		}
		return "";
	}		
	
	//This method helps alleviate the overhead of creating a messenger and starting it.
	//This means a messenger should be created and started and then passed into this method to be
	//used.
	public static String sendWithMessenger(Messenger msgr, String messageText) {
		
		synchronized(msgr) {
			JNIMessageFactory msgFact = new JNIMessageFactory();
			String address = "";
			if(messageText.equals(""))
				messageText = "Default message text";
			
			try{
				Log.v("my-tag","setting outgoing window.");
				msgr.setOutgoingWindow(1);
				Log.v("my-tag","setting timeout to 3 seconds.");
				msgr.setTimeout(3000);;
				Log.v("my-tag","creating a message.");
				Message msg = msgFact.createMessage();
				Log.v("my-tag","setting the message address to : "+address+".");
				msg.setAddress(address);
				UUID id = UUID.randomUUID();
				Log.v("my-tag","setting message id to: "+id+".");
				msg.setMessageId(id);
				Log.v("my-tag","setting the body to '"+messageText+"'.");
				msg.setBody(new AmqpValue(messageText));
				Log.v("my-tag","putting the message.");
				msgr.put(msg);
				Log.v("my-tag","getting outgoing tracker.");
				Tracker tracker = msgr.outgoingTracker();
				Log.v("my-tag","sending the message.");
				msgr.send();
				Log.v("my-tag","send status is "+msgr.getStatus(tracker)+".");
				return msgr.getStatus(tracker).toString();
				
			
			}
			catch(Exception e) {
				Log.v("my log",e.getStackTrace().toString());
			}
			return "";
		
		}
	}
	
	//This method helps alleviate the overhead of creating a messenger and starting it.
	//This means a messenger should be created and started and then passed into this method to be
	//used.	
	public static String receiveWithMessenger(Messenger msgr) {
		String address = "";

		synchronized(msgr) {
		
			try{
				Log.v("my-tag","subscribing to address: "+address);
				msgr.subscribe(address);
				Log.v("my-tag","setting incoming window.");
				msgr.setIncomingWindow(1);
				Log.v("my-tag","setting the messenger timeout to 10 seconds.");
				msgr.setTimeout(3000);
				Log.v("my-tag","Calling msgr.recv()");
				msgr.recv(1);
				Log.v("my-tag","Getting the message from incoming queue");
				Message messageReceived = msgr.get();
				Log.v("my-tag","Getting incoming tracker.");	
				Tracker incTracker = msgr.incomingTracker();
				Log.v("my-tag","Accepting the message.");
				msgr.accept(incTracker, Messenger.CUMULATIVE);
				Log.v("my-tag","returning the message body.");
				return (String)((AmqpValue)(messageReceived.getBody())).getValue();
			}
			catch(Exception e) {
				Log.e("my-tag", e.getStackTrace().toString());
			}
		}
		return null;
	}
	
	public static void longSend() {
		JNIMessengerFactory factory = new JNIMessengerFactory();
		JNIMessageFactory msgFact = new JNIMessageFactory();
		String address = "";		
		
		Messenger msgr = factory.createMessenger();		
		
		try{
			Log.v("my-tag","starting the messenger.");
			msgr.start();
			Log.v("my-tag","setting outgoing window.");
			msgr.setOutgoingWindow(1);
			Log.v("my-tag","creating a message.");
			Message msg = msgFact.createMessage();
			Log.v("my-tag","setting the message address to : "+address+".");
			msg.setAddress(address);
			UUID id = UUID.randomUUID();
			Log.v("my-tag","setting message id to: "+id+".");
			msg.setMessageId(id);
			id = UUID.randomUUID();
			Log.v("my-tag","setting the correlation to: "+id+".");
			msg.setCorrelationId(id);
			Log.v("my-tag","setting replyTo to 'My name'.");
			msg.setReplyTo("My name");
			Log.v("my-tag","setting subject to 'testing properties'.");
			msg.setSubject("testing properties");
			Log.v("my-tag","setting the body to 'Hello world!'.");
			msg.setBody(new AmqpValue("Hello world!"));
			Log.v("my-tag","putting the message.");
			msgr.put(msg);
			Log.v("my-tag","getting outgoing tracker.");
			Tracker tracker = msgr.outgoingTracker();
			Log.v("my-tag","sending the message.");
			msgr.send();
			Log.v("my-tag","send status is "+msgr.getStatus(tracker)+".");
			Log.v("my-tag","stopping the messenger.");			
			msgr.stop();			
		}
		catch(MessengerException e) {
			Log.v("my-tag", e.getMessage());
		}
		catch(Exception e) {
			e.printStackTrace();
		}
	}
		
}
