using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityOSC;

public class SimpleExample : MonoBehaviour {
	
	const string mc_neutral = "/com/neutral";
	const string mc_push    = "/com/push";
	const string mc_pull    = "/com/pull";
	const string mc_left    = "/com/left";
	const string mc_right   = "/com/right";

	private OSCReciever reciever;

	public int port = 8500;
	
	// Use this for initialization
	void Start () {
		reciever = new OSCReciever();
		reciever.Open(port);
	}

	void doAction(string address, float value) {
		if(address.Equals(mc_neutral)) {
			cube.action = 0;
		}
		else if(address.Equals(mc_push)) {
			cube.action = 1;
		}
		else if(address.Equals(mc_pull)) {
			cube.action = 2;
		}
		else if(address.Equals(mc_left)) {
			cube.action = 3;
		}
		else if(address.Equals(mc_right)) {
			cube.action = 4;
		}

		if(value > 0.5)
			cube.doubleSpeed = 2;
		else 
			cube.doubleSpeed = 1;
	}
	
	// Update is called once per frame
	void Update () {
		if(reciever.hasWaitingMessages()) {
			OSCMessage msg = reciever.getNextMessage();
			string msgValue = DataToString(msg.Data);
			doAction(msg.Address, DataToFloat(msg.Data));
			Debug.Log(string.Format("message received: {0} {1}", msg.Address, msgValue));
		}
	}
	
	private string DataToString(List<object> data)
	{
		string buffer = "";
		
		for(int i = 0; i < data.Count; i++)
		{
			buffer += data[i].ToString() + " ";
		}	

		buffer += "\n";
		return buffer;
	}

	private float DataToFloat(List<object> data)
	{
		if (data.Count != 1) {
			Debug.Log("Data not supported");
			return 0;
		}

		return (float)data[0];
	}

	void OnApplicationQuit() {
		reciever.Close();
		Debug.Log("Close OSCReciever");
 	}
}
