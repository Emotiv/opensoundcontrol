using UnityEngine;
using System.Collections;
using UnityEngine.UI;

public class cube : MonoBehaviour {

    enum MC_Action {
        neutral = 0,
        push,
        pull,
        left,
        right
    }

    public Text currentAction;

    public static int action = (int)MC_Action.neutral;
    float last_action = (int)MC_Action.neutral;
    public static float doubleSpeed = 1.0f;
    float speed = 7.0f / 8.0f;

	void Start () {
	}
	
	// Update is called once per frame
	void Update () {

        if(last_action != action) {
            last_action = action;
            transform.localPosition = new Vector3(0, 0, 0);
        }

        switch (action)
        {
            case (int)MC_Action.neutral:
                currentAction.text = "Action: Neutral";
                transform.localPosition = new Vector3(0, 0, 0);
                break;
            case (int)MC_Action.push:
                currentAction.text = "Action: Push";
                if (transform.localPosition.z < 7)
                    transform.Translate(0, 0, speed * Time.deltaTime * doubleSpeed);
                else
                    transform.localPosition = new Vector3(0, 0, 7);
                break;
            case (int)MC_Action.pull:
                currentAction.text = "Action: Pull";
                if (transform.localPosition.z > -7)
                    transform.Translate(0, 0, -speed * Time.deltaTime * doubleSpeed);
                else
                    transform.localPosition = new Vector3(0, 0, -7);
                break;
            case (int)MC_Action.left:
                currentAction.text = "Action: Left";
                if (transform.localPosition.x > -7)
                    transform.Translate(-speed * Time.deltaTime * doubleSpeed, 0, 0);
                else
                    transform.localPosition = new Vector3(-7, 0, 0);
                break;
            case (int)MC_Action.right:
                currentAction.text = "Action: Right";
                if (transform.localPosition.x < 7)
                    transform.Translate(speed * Time.deltaTime * doubleSpeed, 0, 0);
                else
                    transform.localPosition = new Vector3(7, 0, 0);
                break;
            default:
                Debug.Log("Not supported!");
                break;
        }

	    if (action == 0)
        {
            
        }
        else
        {
            
        }
	}
}
