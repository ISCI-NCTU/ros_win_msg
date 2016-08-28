#ifndef _ROS_SERVICE_Logout_h
#define _ROS_SERVICE_Logout_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace program_queue
{

static const char LOGOUT[] = "program_queue/Logout";

  class LogoutRequest : public ros::Msg
  {
    public:
      uint64_t token;

    LogoutRequest():
      token(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        uint64_t real;
        uint32_t base;
      } u_token;
      u_token.real = this->token;
      *(outbuffer + offset + 0) = (u_token.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_token.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_token.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_token.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->token);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        uint64_t real;
        uint32_t base;
      } u_token;
      u_token.base = 0;
      u_token.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_token.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_token.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_token.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->token = u_token.real;
      offset += sizeof(this->token);
     return offset;
    }

    const char * getType(){ return LOGOUT; };
    const char * getMD5(){ return "14c7152ddd08a9946aaadd642a3c327d"; };

  };

  class LogoutResponse : public ros::Msg
  {
    public:

    LogoutResponse()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return LOGOUT; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class Logout {
    public:
    typedef LogoutRequest Request;
    typedef LogoutResponse Response;
  };

}
#endif
