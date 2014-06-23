package com.example.examplesendreceive;

import java.io.IOException;

import org.apache.qpid.proton.messenger.Messenger;
import org.apache.qpid.proton.messenger.jni.JNIMessengerFactory;



import android.app.Activity;
import android.app.ActionBar;
import android.app.Fragment;
import android.os.AsyncTask;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.os.Build;

public class MainActivity extends Activity {

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);

		if (savedInstanceState == null) {
			getFragmentManager().beginTransaction()
					.add(R.id.container, new PlaceholderFragment()).commit();
		}
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {

		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}

	@Override
	public boolean onOptionsItemSelected(MenuItem item) {
		// Handle action bar item clicks here. The action bar will
		// automatically handle clicks on the Home/Up button, so long
		// as you specify a parent activity in AndroidManifest.xml.
		int id = item.getItemId();
		if (id == R.id.action_settings) {
			return true;
		}
		return super.onOptionsItemSelected(item);
	}

	/**
	 * A placeholder fragment containing a simple view.
	 */
	public static class PlaceholderFragment extends Fragment implements OnClickListener{
		JNIMessengerFactory messengerFactory = new JNIMessengerFactory();
		Messenger msgr;
		//boolean to keep track of the messengers started/stopped state.
		boolean stopped = true;
		
		private EditText sendText;
		private TextView centerTV;
		private TextView statusTV;
		private Button sendButton;
		private Button recvButton;
		
		public PlaceholderFragment() {
		}

		@Override
		public View onCreateView(LayoutInflater inflater, ViewGroup container,
				Bundle savedInstanceState) {
			View rootView = inflater.inflate(R.layout.fragment_main, container,
					false);
			//Create the applications messenger.
			msgr = messengerFactory.createMessenger();
			//Start the messenger whenever the android app starts.
			try {
				msgr.start();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			
			sendText = (EditText) rootView.findViewById(R.id.sendText);
			centerTV = (TextView) rootView.findViewById(R.id.centerTV);
			statusTV = (TextView) rootView.findViewById(R.id.statusTV);
			sendButton = (Button) rootView.findViewById(R.id.sendButton);
			recvButton = (Button) rootView.findViewById(R.id.recvButton);
			sendButton.setOnClickListener(this);
			recvButton.setOnClickListener(this);

			return rootView;
		}
		
		@Override
		public void onResume() {
			super.onResume();
			if(msgr.stopped()) {
				try{
					msgr.start();
				}
				catch(Exception e) {}
			}
		}
		
		@Override
		public void onPause() {
			if(!msgr.stopped())
				msgr.stop();
			super.onPause();
		}
		
		
		public class AsyncSend extends AsyncTask<Object,Object,String> {

			Messenger sendMessenger;
			String messageText;
			
			AsyncSend(Messenger m, String messageText) {
				sendMessenger = m;
				if(messageText.equals(""))
					this.messageText = "Default message";
				else
					this.messageText = messageText;
			}
			@Override
			protected void onPreExecute() {
				statusTV.setText("Starting a send");
			}
			
			@Override
			protected String doInBackground(Object... params) {
				return UsingSwig.sendWithMessenger(sendMessenger,messageText);

			}
			
			@Override
			protected void onPostExecute(String result) {
				if(!result.equals("")) {
					statusTV.setText("Send status is: "+result);
					centerTV.setText("Sent: "+messageText);
				}
				else {
					statusTV.setText("Something happened with a send.");
				}
				
			}
			
		}
		
		public class AsyncRecv extends AsyncTask<Object,Object,String>{

			Messenger receiveMessenger;
			AsyncRecv(Messenger m) {
				this.receiveMessenger = m;
			}
			
			@Override
			protected void onPreExecute() {
				statusTV.setText("Starting a receive");
			}
			
			@Override
			protected String doInBackground(Object... params) {
				return UsingSwig.receiveWithMessenger(receiveMessenger);
			}
			
			@Override
			protected void onPostExecute(String result) {
				if(result == null)
				{
					statusTV.setText("Didn't receive anything.");
					centerTV.setText("Message queue is empty or error occured.");
				}
				else if(!result.equals("")) {
					centerTV.setText("Received: "+result);
					statusTV.setText("Finished a receive");
				}
			}
			
		}

		@Override
		public void onClick(View v) {
			
			switch(v.getId()){
			case R.id.sendButton:
				new AsyncSend(msgr,sendText.getText().toString()).execute();
				break;
			case R.id.recvButton:
				new AsyncRecv(msgr).execute()	;
				break;
			default: break;
			}
		}
		
		
		
		
	}//end class PlaceholderFragment

}//end class MainActivity
