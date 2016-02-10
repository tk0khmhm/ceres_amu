/* Auto-generated by genmsg_cpp for file /home/amsl/AMSL_ros_pkg/ceres_amu/msg/AMU.msg */
#ifndef CERES_AMU_MESSAGE_AMU_H
#define CERES_AMU_MESSAGE_AMU_H
#include <string>
#include <vector>
#include <map>
#include <ostream>
#include "ros/serialization.h"
#include "ros/builtin_message_traits.h"
#include "ros/message_operations.h"
#include "ros/time.h"

#include "ros/macros.h"

#include "ros/assert.h"


namespace ceres_amu
{
template <class ContainerAllocator>
struct AMU_ {
  typedef AMU_<ContainerAllocator> Type;

  AMU_()
  : xaccel(0.0)
  , yaccel(0.0)
  , zaccel(0.0)
  , droll(0.0)
  , dpitch(0.0)
  , dyaw(0.0)
  , roll(0.0)
  , pitch(0.0)
  , yaw(0.0)
  , status(0.0)
  {
  }

  AMU_(const ContainerAllocator& _alloc)
  : xaccel(0.0)
  , yaccel(0.0)
  , zaccel(0.0)
  , droll(0.0)
  , dpitch(0.0)
  , dyaw(0.0)
  , roll(0.0)
  , pitch(0.0)
  , yaw(0.0)
  , status(0.0)
  {
  }

  typedef float _xaccel_type;
  float xaccel;

  typedef float _yaccel_type;
  float yaccel;

  typedef float _zaccel_type;
  float zaccel;

  typedef float _droll_type;
  float droll;

  typedef float _dpitch_type;
  float dpitch;

  typedef float _dyaw_type;
  float dyaw;

  typedef float _roll_type;
  float roll;

  typedef float _pitch_type;
  float pitch;

  typedef float _yaw_type;
  float yaw;

  typedef float _status_type;
  float status;


  typedef boost::shared_ptr< ::ceres_amu::AMU_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ceres_amu::AMU_<ContainerAllocator>  const> ConstPtr;
}; // struct AMU
typedef  ::ceres_amu::AMU_<std::allocator<void> > AMU;

typedef boost::shared_ptr< ::ceres_amu::AMU> AMUPtr;
typedef boost::shared_ptr< ::ceres_amu::AMU const> AMUConstPtr;


template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const  ::ceres_amu::AMU_<ContainerAllocator> & v)
{
  ros::message_operations::Printer< ::ceres_amu::AMU_<ContainerAllocator> >::stream(s, "", v);
  return s;}

} // namespace ceres_amu

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::ceres_amu::AMU_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::ceres_amu::AMU_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::ceres_amu::AMU_<ContainerAllocator> > {
  static const char* value() 
  {
    return "dbdcdf66fe0e5834bd3a982cef95bb82";
  }

  static const char* value(const  ::ceres_amu::AMU_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0xdbdcdf66fe0e5834ULL;
  static const uint64_t static_value2 = 0xbd3a982cef95bb82ULL;
};

template<class ContainerAllocator>
struct DataType< ::ceres_amu::AMU_<ContainerAllocator> > {
  static const char* value() 
  {
    return "ceres_amu/AMU";
  }

  static const char* value(const  ::ceres_amu::AMU_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::ceres_amu::AMU_<ContainerAllocator> > {
  static const char* value() 
  {
    return "float32 xaccel # G \n\
float32 yaccel\n\
float32 zaccel\n\
\n\
float32 droll  # deg/sec\n\
float32 dpitch\n\
float32 dyaw\n\
\n\
float32 roll   # deg\n\
float32 pitch\n\
float32 yaw\n\
\n\
float32 status\n\
\n\
";
  }

  static const char* value(const  ::ceres_amu::AMU_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator> struct IsFixedSize< ::ceres_amu::AMU_<ContainerAllocator> > : public TrueType {};
} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::ceres_amu::AMU_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.xaccel);
    stream.next(m.yaccel);
    stream.next(m.zaccel);
    stream.next(m.droll);
    stream.next(m.dpitch);
    stream.next(m.dyaw);
    stream.next(m.roll);
    stream.next(m.pitch);
    stream.next(m.yaw);
    stream.next(m.status);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct AMU_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ceres_amu::AMU_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const  ::ceres_amu::AMU_<ContainerAllocator> & v) 
  {
    s << indent << "xaccel: ";
    Printer<float>::stream(s, indent + "  ", v.xaccel);
    s << indent << "yaccel: ";
    Printer<float>::stream(s, indent + "  ", v.yaccel);
    s << indent << "zaccel: ";
    Printer<float>::stream(s, indent + "  ", v.zaccel);
    s << indent << "droll: ";
    Printer<float>::stream(s, indent + "  ", v.droll);
    s << indent << "dpitch: ";
    Printer<float>::stream(s, indent + "  ", v.dpitch);
    s << indent << "dyaw: ";
    Printer<float>::stream(s, indent + "  ", v.dyaw);
    s << indent << "roll: ";
    Printer<float>::stream(s, indent + "  ", v.roll);
    s << indent << "pitch: ";
    Printer<float>::stream(s, indent + "  ", v.pitch);
    s << indent << "yaw: ";
    Printer<float>::stream(s, indent + "  ", v.yaw);
    s << indent << "status: ";
    Printer<float>::stream(s, indent + "  ", v.status);
  }
};


} // namespace message_operations
} // namespace ros

#endif // CERES_AMU_MESSAGE_AMU_H

