// Generated by gencpp from file RosIceMessage/EncodersData.msg
// DO NOT EDIT!


#ifndef ROSICEMESSAGE_MESSAGE_ENCODERSDATA_H
#define ROSICEMESSAGE_MESSAGE_ENCODERSDATA_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace RosIceMessage
{
template <class ContainerAllocator>
struct EncodersData_
{
  typedef EncodersData_<ContainerAllocator> Type;

  EncodersData_()
    : robotx(0.0)
    , roboty(0.0)
    , robottheta(0.0)
    , robotcos(0.0)
    , robotsin(0.0)  {
    }
  EncodersData_(const ContainerAllocator& _alloc)
    : robotx(0.0)
    , roboty(0.0)
    , robottheta(0.0)
    , robotcos(0.0)
    , robotsin(0.0)  {
    }



   typedef float _robotx_type;
  _robotx_type robotx;

   typedef float _roboty_type;
  _roboty_type roboty;

   typedef float _robottheta_type;
  _robottheta_type robottheta;

   typedef float _robotcos_type;
  _robotcos_type robotcos;

   typedef float _robotsin_type;
  _robotsin_type robotsin;




  typedef boost::shared_ptr< ::RosIceMessage::EncodersData_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::RosIceMessage::EncodersData_<ContainerAllocator> const> ConstPtr;

}; // struct EncodersData_

typedef ::RosIceMessage::EncodersData_<std::allocator<void> > EncodersData;

typedef boost::shared_ptr< ::RosIceMessage::EncodersData > EncodersDataPtr;
typedef boost::shared_ptr< ::RosIceMessage::EncodersData const> EncodersDataConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::RosIceMessage::EncodersData_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::RosIceMessage::EncodersData_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace RosIceMessage

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'geometry_msgs': ['/opt/ros/jade/share/geometry_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/jade/share/std_msgs/cmake/../msg'], 'RosIceMessage': ['/home/ace15/Documents/JdeRobot/GoogleSummer/JdeRobot2015/catkin_ws/src/RosIceMessage/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::RosIceMessage::EncodersData_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::RosIceMessage::EncodersData_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::RosIceMessage::EncodersData_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::RosIceMessage::EncodersData_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::RosIceMessage::EncodersData_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::RosIceMessage::EncodersData_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::RosIceMessage::EncodersData_<ContainerAllocator> >
{
  static const char* value()
  {
    return "83a6a0f3f744a58b80321da5cc48ce9e";
  }

  static const char* value(const ::RosIceMessage::EncodersData_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x83a6a0f3f744a58bULL;
  static const uint64_t static_value2 = 0x80321da5cc48ce9eULL;
};

template<class ContainerAllocator>
struct DataType< ::RosIceMessage::EncodersData_<ContainerAllocator> >
{
  static const char* value()
  {
    return "RosIceMessage/EncodersData";
  }

  static const char* value(const ::RosIceMessage::EncodersData_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::RosIceMessage::EncodersData_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float32 robotx\n\
float32 roboty\n\
float32 robottheta\n\
float32 robotcos\n\
float32 robotsin\n\
";
  }

  static const char* value(const ::RosIceMessage::EncodersData_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::RosIceMessage::EncodersData_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.robotx);
      stream.next(m.roboty);
      stream.next(m.robottheta);
      stream.next(m.robotcos);
      stream.next(m.robotsin);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct EncodersData_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::RosIceMessage::EncodersData_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::RosIceMessage::EncodersData_<ContainerAllocator>& v)
  {
    s << indent << "robotx: ";
    Printer<float>::stream(s, indent + "  ", v.robotx);
    s << indent << "roboty: ";
    Printer<float>::stream(s, indent + "  ", v.roboty);
    s << indent << "robottheta: ";
    Printer<float>::stream(s, indent + "  ", v.robottheta);
    s << indent << "robotcos: ";
    Printer<float>::stream(s, indent + "  ", v.robotcos);
    s << indent << "robotsin: ";
    Printer<float>::stream(s, indent + "  ", v.robotsin);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROSICEMESSAGE_MESSAGE_ENCODERSDATA_H
