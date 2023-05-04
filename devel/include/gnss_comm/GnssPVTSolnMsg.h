// Generated by gencpp from file gnss_comm/GnssPVTSolnMsg.msg
// DO NOT EDIT!


#ifndef GNSS_COMM_MESSAGE_GNSSPVTSOLNMSG_H
#define GNSS_COMM_MESSAGE_GNSSPVTSOLNMSG_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <gnss_comm/GnssTimeMsg.h>

namespace gnss_comm
{
template <class ContainerAllocator>
struct GnssPVTSolnMsg_
{
  typedef GnssPVTSolnMsg_<ContainerAllocator> Type;

  GnssPVTSolnMsg_()
    : time()
    , fix_type(0)
    , valid_fix(false)
    , diff_soln(false)
    , carr_soln(0)
    , num_sv(0)
    , latitude(0.0)
    , longitude(0.0)
    , altitude(0.0)
    , height_msl(0.0)
    , h_acc(0.0)
    , v_acc(0.0)
    , p_dop(0.0)
    , vel_n(0.0)
    , vel_e(0.0)
    , vel_d(0.0)
    , vel_acc(0.0)  {
    }
  GnssPVTSolnMsg_(const ContainerAllocator& _alloc)
    : time(_alloc)
    , fix_type(0)
    , valid_fix(false)
    , diff_soln(false)
    , carr_soln(0)
    , num_sv(0)
    , latitude(0.0)
    , longitude(0.0)
    , altitude(0.0)
    , height_msl(0.0)
    , h_acc(0.0)
    , v_acc(0.0)
    , p_dop(0.0)
    , vel_n(0.0)
    , vel_e(0.0)
    , vel_d(0.0)
    , vel_acc(0.0)  {
  (void)_alloc;
    }



   typedef  ::gnss_comm::GnssTimeMsg_<ContainerAllocator>  _time_type;
  _time_type time;

   typedef uint8_t _fix_type_type;
  _fix_type_type fix_type;

   typedef uint8_t _valid_fix_type;
  _valid_fix_type valid_fix;

   typedef uint8_t _diff_soln_type;
  _diff_soln_type diff_soln;

   typedef uint8_t _carr_soln_type;
  _carr_soln_type carr_soln;

   typedef uint8_t _num_sv_type;
  _num_sv_type num_sv;

   typedef double _latitude_type;
  _latitude_type latitude;

   typedef double _longitude_type;
  _longitude_type longitude;

   typedef double _altitude_type;
  _altitude_type altitude;

   typedef double _height_msl_type;
  _height_msl_type height_msl;

   typedef double _h_acc_type;
  _h_acc_type h_acc;

   typedef double _v_acc_type;
  _v_acc_type v_acc;

   typedef double _p_dop_type;
  _p_dop_type p_dop;

   typedef double _vel_n_type;
  _vel_n_type vel_n;

   typedef double _vel_e_type;
  _vel_e_type vel_e;

   typedef double _vel_d_type;
  _vel_d_type vel_d;

   typedef double _vel_acc_type;
  _vel_acc_type vel_acc;





  typedef boost::shared_ptr< ::gnss_comm::GnssPVTSolnMsg_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::gnss_comm::GnssPVTSolnMsg_<ContainerAllocator> const> ConstPtr;

}; // struct GnssPVTSolnMsg_

typedef ::gnss_comm::GnssPVTSolnMsg_<std::allocator<void> > GnssPVTSolnMsg;

typedef boost::shared_ptr< ::gnss_comm::GnssPVTSolnMsg > GnssPVTSolnMsgPtr;
typedef boost::shared_ptr< ::gnss_comm::GnssPVTSolnMsg const> GnssPVTSolnMsgConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::gnss_comm::GnssPVTSolnMsg_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::gnss_comm::GnssPVTSolnMsg_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::gnss_comm::GnssPVTSolnMsg_<ContainerAllocator1> & lhs, const ::gnss_comm::GnssPVTSolnMsg_<ContainerAllocator2> & rhs)
{
  return lhs.time == rhs.time &&
    lhs.fix_type == rhs.fix_type &&
    lhs.valid_fix == rhs.valid_fix &&
    lhs.diff_soln == rhs.diff_soln &&
    lhs.carr_soln == rhs.carr_soln &&
    lhs.num_sv == rhs.num_sv &&
    lhs.latitude == rhs.latitude &&
    lhs.longitude == rhs.longitude &&
    lhs.altitude == rhs.altitude &&
    lhs.height_msl == rhs.height_msl &&
    lhs.h_acc == rhs.h_acc &&
    lhs.v_acc == rhs.v_acc &&
    lhs.p_dop == rhs.p_dop &&
    lhs.vel_n == rhs.vel_n &&
    lhs.vel_e == rhs.vel_e &&
    lhs.vel_d == rhs.vel_d &&
    lhs.vel_acc == rhs.vel_acc;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::gnss_comm::GnssPVTSolnMsg_<ContainerAllocator1> & lhs, const ::gnss_comm::GnssPVTSolnMsg_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace gnss_comm

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::gnss_comm::GnssPVTSolnMsg_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::gnss_comm::GnssPVTSolnMsg_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::gnss_comm::GnssPVTSolnMsg_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::gnss_comm::GnssPVTSolnMsg_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::gnss_comm::GnssPVTSolnMsg_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::gnss_comm::GnssPVTSolnMsg_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::gnss_comm::GnssPVTSolnMsg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "d18171357d7a159f76d4d7c0b12fb631";
  }

  static const char* value(const ::gnss_comm::GnssPVTSolnMsg_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xd18171357d7a159fULL;
  static const uint64_t static_value2 = 0x76d4d7c0b12fb631ULL;
};

template<class ContainerAllocator>
struct DataType< ::gnss_comm::GnssPVTSolnMsg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "gnss_comm/GnssPVTSolnMsg";
  }

  static const char* value(const ::gnss_comm::GnssPVTSolnMsg_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::gnss_comm::GnssPVTSolnMsg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# This message contains information of UBX-NAV-PVT message. \n"
"# reference: [1]. UBX-18010854-R08, page 132\n"
"\n"
"GnssTimeMsg time    # GNSS time of the navigation epoch\n"
"# GNSS fix type (0=no fix, 1=dead reckoning only, 2=2D-fix, 3=3D-fix, \n"
"# 4=GNSS+dead reckoning combined, 5=time only fix)\n"
"uint8   fix_type\n"
"bool    valid_fix   # if fix valid (1=valid fix)\n"
"bool    diff_soln   # if differential correction were applied (1=applied)\n"
"uint8   carr_soln   # carrier phase range solution status (0=no carrier phase, 1=float, 2=fix)\n"
"uint8   num_sv      # number of satellites used in the solution\n"
"float64 latitude    # latitude [degree]\n"
"float64 longitude   # longitude [degree]\n"
"float64 altitude    # height above ellipsoid [m]\n"
"float64 height_msl  # height above mean sea level [m]\n"
"float64 h_acc       # horizontal accuracy estimate [m]\n"
"float64 v_acc       # vertical accuracy estimate [m]\n"
"float64 p_dop       # Position DOP\n"
"float64 vel_n       # NED north velocity [m/s]\n"
"float64 vel_e       # NED east velocity [m/s]\n"
"float64 vel_d       # NED down velocity [m/s]\n"
"float64 vel_acc     # speed accuracy estimate [m/s]\n"
"\n"
"================================================================================\n"
"MSG: gnss_comm/GnssTimeMsg\n"
"# This message contains GNSS time expressed in the form of \n"
"# GNSS week number and time of week(in seconds)\n"
"\n"
"uint32 week\n"
"float64 tow\n"
;
  }

  static const char* value(const ::gnss_comm::GnssPVTSolnMsg_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::gnss_comm::GnssPVTSolnMsg_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.time);
      stream.next(m.fix_type);
      stream.next(m.valid_fix);
      stream.next(m.diff_soln);
      stream.next(m.carr_soln);
      stream.next(m.num_sv);
      stream.next(m.latitude);
      stream.next(m.longitude);
      stream.next(m.altitude);
      stream.next(m.height_msl);
      stream.next(m.h_acc);
      stream.next(m.v_acc);
      stream.next(m.p_dop);
      stream.next(m.vel_n);
      stream.next(m.vel_e);
      stream.next(m.vel_d);
      stream.next(m.vel_acc);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct GnssPVTSolnMsg_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::gnss_comm::GnssPVTSolnMsg_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::gnss_comm::GnssPVTSolnMsg_<ContainerAllocator>& v)
  {
    s << indent << "time: ";
    s << std::endl;
    Printer< ::gnss_comm::GnssTimeMsg_<ContainerAllocator> >::stream(s, indent + "  ", v.time);
    s << indent << "fix_type: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.fix_type);
    s << indent << "valid_fix: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.valid_fix);
    s << indent << "diff_soln: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.diff_soln);
    s << indent << "carr_soln: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.carr_soln);
    s << indent << "num_sv: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.num_sv);
    s << indent << "latitude: ";
    Printer<double>::stream(s, indent + "  ", v.latitude);
    s << indent << "longitude: ";
    Printer<double>::stream(s, indent + "  ", v.longitude);
    s << indent << "altitude: ";
    Printer<double>::stream(s, indent + "  ", v.altitude);
    s << indent << "height_msl: ";
    Printer<double>::stream(s, indent + "  ", v.height_msl);
    s << indent << "h_acc: ";
    Printer<double>::stream(s, indent + "  ", v.h_acc);
    s << indent << "v_acc: ";
    Printer<double>::stream(s, indent + "  ", v.v_acc);
    s << indent << "p_dop: ";
    Printer<double>::stream(s, indent + "  ", v.p_dop);
    s << indent << "vel_n: ";
    Printer<double>::stream(s, indent + "  ", v.vel_n);
    s << indent << "vel_e: ";
    Printer<double>::stream(s, indent + "  ", v.vel_e);
    s << indent << "vel_d: ";
    Printer<double>::stream(s, indent + "  ", v.vel_d);
    s << indent << "vel_acc: ";
    Printer<double>::stream(s, indent + "  ", v.vel_acc);
  }
};

} // namespace message_operations
} // namespace ros

#endif // GNSS_COMM_MESSAGE_GNSSPVTSOLNMSG_H