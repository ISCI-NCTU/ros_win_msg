#ifndef _ROS_mrpt_msgs_ObservationRangeBeacon_h
#define _ROS_mrpt_msgs_ObservationRangeBeacon_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Pose.h"
#include "mrpt_msgs/SingleRangeBeaconObservation.h"

namespace mrpt_msgs
{

  class ObservationRangeBeacon : public ros::Msg
  {
    public:
      std_msgs::Header header;
      geometry_msgs::Pose sensor_pose_on_robot;
      double min_sensor_distance;
      double max_sensor_distance;
      double sensor_std_range;
      uint8_t sensed_data_length;
      mrpt_msgs::SingleRangeBeaconObservation st_sensed_data;
      mrpt_msgs::SingleRangeBeaconObservation * sensed_data;

    ObservationRangeBeacon():
      header(),
      sensor_pose_on_robot(),
      min_sensor_distance(0),
      max_sensor_distance(0),
      sensor_std_range(0),
      sensed_data_length(0), sensed_data(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->sensor_pose_on_robot.serialize(outbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_min_sensor_distance;
      u_min_sensor_distance.real = this->min_sensor_distance;
      *(outbuffer + offset + 0) = (u_min_sensor_distance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_min_sensor_distance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_min_sensor_distance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_min_sensor_distance.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_min_sensor_distance.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_min_sensor_distance.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_min_sensor_distance.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_min_sensor_distance.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->min_sensor_distance);
      union {
        double real;
        uint64_t base;
      } u_max_sensor_distance;
      u_max_sensor_distance.real = this->max_sensor_distance;
      *(outbuffer + offset + 0) = (u_max_sensor_distance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_sensor_distance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max_sensor_distance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max_sensor_distance.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_max_sensor_distance.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_max_sensor_distance.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_max_sensor_distance.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_max_sensor_distance.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->max_sensor_distance);
      union {
        double real;
        uint64_t base;
      } u_sensor_std_range;
      u_sensor_std_range.real = this->sensor_std_range;
      *(outbuffer + offset + 0) = (u_sensor_std_range.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_sensor_std_range.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_sensor_std_range.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_sensor_std_range.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_sensor_std_range.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_sensor_std_range.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_sensor_std_range.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_sensor_std_range.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->sensor_std_range);
      *(outbuffer + offset++) = sensed_data_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < sensed_data_length; i++){
      offset += this->sensed_data[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->sensor_pose_on_robot.deserialize(inbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_min_sensor_distance;
      u_min_sensor_distance.base = 0;
      u_min_sensor_distance.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_min_sensor_distance.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_min_sensor_distance.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_min_sensor_distance.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_min_sensor_distance.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_min_sensor_distance.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_min_sensor_distance.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_min_sensor_distance.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->min_sensor_distance = u_min_sensor_distance.real;
      offset += sizeof(this->min_sensor_distance);
      union {
        double real;
        uint64_t base;
      } u_max_sensor_distance;
      u_max_sensor_distance.base = 0;
      u_max_sensor_distance.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_sensor_distance.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max_sensor_distance.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max_sensor_distance.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_max_sensor_distance.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_max_sensor_distance.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_max_sensor_distance.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_max_sensor_distance.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->max_sensor_distance = u_max_sensor_distance.real;
      offset += sizeof(this->max_sensor_distance);
      union {
        double real;
        uint64_t base;
      } u_sensor_std_range;
      u_sensor_std_range.base = 0;
      u_sensor_std_range.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_sensor_std_range.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_sensor_std_range.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_sensor_std_range.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_sensor_std_range.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_sensor_std_range.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_sensor_std_range.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_sensor_std_range.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->sensor_std_range = u_sensor_std_range.real;
      offset += sizeof(this->sensor_std_range);
      uint8_t sensed_data_lengthT = *(inbuffer + offset++);
      if(sensed_data_lengthT > sensed_data_length)
        this->sensed_data = (mrpt_msgs::SingleRangeBeaconObservation*)realloc(this->sensed_data, sensed_data_lengthT * sizeof(mrpt_msgs::SingleRangeBeaconObservation));
      offset += 3;
      sensed_data_length = sensed_data_lengthT;
      for( uint8_t i = 0; i < sensed_data_length; i++){
      offset += this->st_sensed_data.deserialize(inbuffer + offset);
        memcpy( &(this->sensed_data[i]), &(this->st_sensed_data), sizeof(mrpt_msgs::SingleRangeBeaconObservation));
      }
     return offset;
    }

    const char * getType(){ return "mrpt_msgs/ObservationRangeBeacon"; };
    const char * getMD5(){ return "94cf8974a1eec8843e3b69c87cc25d62"; };

  };

}
#endif