
// Check if the environment is Node.js and if so import the required library.
if (typeof exports !== "undefined" && exports !== null) {
    Module = require("../../../bld/proton-c/bindings/javascript/messenger.js");
}


try {

    var messenger = Module.Messenger();

    console.log("name = " + messenger.getName());

    console.log("timeout = " + messenger.getTimeout());

    console.log("isBlocking = " + messenger.isBlocking());

    messenger.setIncomingWindow(1234);
    console.log("incoming window = " + messenger.getIncomingWindow());

    messenger.setOutgoingWindow(5678);
    console.log("outgoing window = " + messenger.getOutgoingWindow());


    messenger.start();
    console.log("isStopped = " + messenger.isStopped());


    //messenger.subscribe("amqp://narnia");
    var subscription = messenger.subscribe("amqp://~0.0.0.0");
    console.log("subscription address = " + subscription.getAddress());



    messenger.stop();
    console.log("isStopped = " + messenger.isStopped());

    messenger.free();

} catch(e) {
    console.log("Caught Exception " + e);
}
