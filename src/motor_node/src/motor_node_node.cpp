#include "motor_node/motor_node.h"
int main(int argc, char **argv)
  {
    ros::init(argc, argv, "motor_node_node");
    ros::NodeHandle nodeHandle;

ros::Time
      last,
      now;
    now = last = ros::Time::now();
    ros::Duration period(1.0);

    ros::AsyncSpinner spinner(2);
    spinner.start();   
 while ( ros::ok() )
    {
      now = ros::Time::now();
      period = now - last;
      last = now;
   // project code start

	int lResult = MMC_FAILED;
        unsigned int ulErrorCode = 0;

        PrintHeader();

        SetDefaultParameters();

        if((lResult = ParseArguments(argc, argv))!=MMC_SUCCESS)
        {
                return lResult;
        }

        PrintSettings();

        if((lResult = OpenDevice(&ulErrorCode))!=MMC_SUCCESS)
        {
                LogError("OpenDevice", lResult, ulErrorCode);
                return lResult;
        }

        if((lResult = PrepareDemo(&ulErrorCode))!=MMC_SUCCESS)
        {
                LogError("PrepareDemo", lResult, ulErrorCode);
                return lResult;
        }

        if((lResult = Demo(&ulErrorCode))!=MMC_SUCCESS)
        {
                LogError("Demo", lResult, ulErrorCode);
                return lResult;
        }

        if((lResult = CloseDevice(&ulErrorCode))!=MMC_SUCCESS)
        {
                LogError("CloseDevice", lResult, ulErrorCode);
                return lResult;
        }

        return lResult;

  // project code finish


      ros::Duration(0.2).sleep();
    }
    spinner.stop();
    return 0;
  }

