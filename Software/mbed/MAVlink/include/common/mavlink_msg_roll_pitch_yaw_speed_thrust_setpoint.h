// MESSAGE ROLL_PITCH_YAW_SPEED_THRUST_SETPOINT PACKING

#define MAVLINK_MSG_ID_ROLL_PITCH_YAW_SPEED_THRUST_SETPOINT 58

typedef struct __mavlink_roll_pitch_yaw_speed_thrust_setpoint_t 
{
    uint64_t time_us; ///< Timestamp in micro seconds since unix epoch
    float roll_speed; ///< Desired roll angular speed in rad/s
    float pitch_speed; ///< Desired pitch angular speed in rad/s
    float yaw_speed; ///< Desired yaw angular speed in rad/s
    float thrust; ///< Collective thrust, normalized to 0 .. 1

} mavlink_roll_pitch_yaw_speed_thrust_setpoint_t;



/**
 * @brief Pack a roll_pitch_yaw_speed_thrust_setpoint message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_us Timestamp in micro seconds since unix epoch
 * @param roll_speed Desired roll angular speed in rad/s
 * @param pitch_speed Desired pitch angular speed in rad/s
 * @param yaw_speed Desired yaw angular speed in rad/s
 * @param thrust Collective thrust, normalized to 0 .. 1
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_roll_pitch_yaw_speed_thrust_setpoint_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, uint64_t time_us, float roll_speed, float pitch_speed, float yaw_speed, float thrust)
{
    uint16_t i = 0;
    msg->msgid = MAVLINK_MSG_ID_ROLL_PITCH_YAW_SPEED_THRUST_SETPOINT;

    i += put_uint64_t_by_index(time_us, i, msg->payload); // Timestamp in micro seconds since unix epoch
    i += put_float_by_index(roll_speed, i, msg->payload); // Desired roll angular speed in rad/s
    i += put_float_by_index(pitch_speed, i, msg->payload); // Desired pitch angular speed in rad/s
    i += put_float_by_index(yaw_speed, i, msg->payload); // Desired yaw angular speed in rad/s
    i += put_float_by_index(thrust, i, msg->payload); // Collective thrust, normalized to 0 .. 1

    return mavlink_finalize_message(msg, system_id, component_id, i);
}

/**
 * @brief Pack a roll_pitch_yaw_speed_thrust_setpoint message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_us Timestamp in micro seconds since unix epoch
 * @param roll_speed Desired roll angular speed in rad/s
 * @param pitch_speed Desired pitch angular speed in rad/s
 * @param yaw_speed Desired yaw angular speed in rad/s
 * @param thrust Collective thrust, normalized to 0 .. 1
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_roll_pitch_yaw_speed_thrust_setpoint_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, uint64_t time_us, float roll_speed, float pitch_speed, float yaw_speed, float thrust)
{
    uint16_t i = 0;
    msg->msgid = MAVLINK_MSG_ID_ROLL_PITCH_YAW_SPEED_THRUST_SETPOINT;

    i += put_uint64_t_by_index(time_us, i, msg->payload); // Timestamp in micro seconds since unix epoch
    i += put_float_by_index(roll_speed, i, msg->payload); // Desired roll angular speed in rad/s
    i += put_float_by_index(pitch_speed, i, msg->payload); // Desired pitch angular speed in rad/s
    i += put_float_by_index(yaw_speed, i, msg->payload); // Desired yaw angular speed in rad/s
    i += put_float_by_index(thrust, i, msg->payload); // Collective thrust, normalized to 0 .. 1

    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, i);
}

/**
 * @brief Encode a roll_pitch_yaw_speed_thrust_setpoint struct into a message
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param roll_pitch_yaw_speed_thrust_setpoint C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_roll_pitch_yaw_speed_thrust_setpoint_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_roll_pitch_yaw_speed_thrust_setpoint_t* roll_pitch_yaw_speed_thrust_setpoint)
{
    return mavlink_msg_roll_pitch_yaw_speed_thrust_setpoint_pack(system_id, component_id, msg, roll_pitch_yaw_speed_thrust_setpoint->time_us, roll_pitch_yaw_speed_thrust_setpoint->roll_speed, roll_pitch_yaw_speed_thrust_setpoint->pitch_speed, roll_pitch_yaw_speed_thrust_setpoint->yaw_speed, roll_pitch_yaw_speed_thrust_setpoint->thrust);
}

/**
 * @brief Send a roll_pitch_yaw_speed_thrust_setpoint message
 * @param chan MAVLink channel to send the message
 *
 * @param time_us Timestamp in micro seconds since unix epoch
 * @param roll_speed Desired roll angular speed in rad/s
 * @param pitch_speed Desired pitch angular speed in rad/s
 * @param yaw_speed Desired yaw angular speed in rad/s
 * @param thrust Collective thrust, normalized to 0 .. 1
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_roll_pitch_yaw_speed_thrust_setpoint_send(mavlink_channel_t chan, uint64_t time_us, float roll_speed, float pitch_speed, float yaw_speed, float thrust)
{
    mavlink_message_t msg;
    mavlink_msg_roll_pitch_yaw_speed_thrust_setpoint_pack_chan(mavlink_system.sysid, mavlink_system.compid, chan, &msg, time_us, roll_speed, pitch_speed, yaw_speed, thrust);
    mavlink_send_uart(chan, &msg);
}

#endif
// MESSAGE ROLL_PITCH_YAW_SPEED_THRUST_SETPOINT UNPACKING

/**
 * @brief Get field time_us from roll_pitch_yaw_speed_thrust_setpoint message
 *
 * @return Timestamp in micro seconds since unix epoch
 */
static inline uint64_t mavlink_msg_roll_pitch_yaw_speed_thrust_setpoint_get_time_us(const mavlink_message_t* msg)
{
    generic_64bit r;
    r.b[7] = (msg->payload)[0];
    r.b[6] = (msg->payload)[1];
    r.b[5] = (msg->payload)[2];
    r.b[4] = (msg->payload)[3];
    r.b[3] = (msg->payload)[4];
    r.b[2] = (msg->payload)[5];
    r.b[1] = (msg->payload)[6];
    r.b[0] = (msg->payload)[7];
    return (uint64_t)r.ll;
}

/**
 * @brief Get field roll_speed from roll_pitch_yaw_speed_thrust_setpoint message
 *
 * @return Desired roll angular speed in rad/s
 */
static inline float mavlink_msg_roll_pitch_yaw_speed_thrust_setpoint_get_roll_speed(const mavlink_message_t* msg)
{
    generic_32bit r;
    r.b[3] = (msg->payload+sizeof(uint64_t))[0];
    r.b[2] = (msg->payload+sizeof(uint64_t))[1];
    r.b[1] = (msg->payload+sizeof(uint64_t))[2];
    r.b[0] = (msg->payload+sizeof(uint64_t))[3];
    return (float)r.f;
}

/**
 * @brief Get field pitch_speed from roll_pitch_yaw_speed_thrust_setpoint message
 *
 * @return Desired pitch angular speed in rad/s
 */
static inline float mavlink_msg_roll_pitch_yaw_speed_thrust_setpoint_get_pitch_speed(const mavlink_message_t* msg)
{
    generic_32bit r;
    r.b[3] = (msg->payload+sizeof(uint64_t)+sizeof(float))[0];
    r.b[2] = (msg->payload+sizeof(uint64_t)+sizeof(float))[1];
    r.b[1] = (msg->payload+sizeof(uint64_t)+sizeof(float))[2];
    r.b[0] = (msg->payload+sizeof(uint64_t)+sizeof(float))[3];
    return (float)r.f;
}

/**
 * @brief Get field yaw_speed from roll_pitch_yaw_speed_thrust_setpoint message
 *
 * @return Desired yaw angular speed in rad/s
 */
static inline float mavlink_msg_roll_pitch_yaw_speed_thrust_setpoint_get_yaw_speed(const mavlink_message_t* msg)
{
    generic_32bit r;
    r.b[3] = (msg->payload+sizeof(uint64_t)+sizeof(float)+sizeof(float))[0];
    r.b[2] = (msg->payload+sizeof(uint64_t)+sizeof(float)+sizeof(float))[1];
    r.b[1] = (msg->payload+sizeof(uint64_t)+sizeof(float)+sizeof(float))[2];
    r.b[0] = (msg->payload+sizeof(uint64_t)+sizeof(float)+sizeof(float))[3];
    return (float)r.f;
}

/**
 * @brief Get field thrust from roll_pitch_yaw_speed_thrust_setpoint message
 *
 * @return Collective thrust, normalized to 0 .. 1
 */
static inline float mavlink_msg_roll_pitch_yaw_speed_thrust_setpoint_get_thrust(const mavlink_message_t* msg)
{
    generic_32bit r;
    r.b[3] = (msg->payload+sizeof(uint64_t)+sizeof(float)+sizeof(float)+sizeof(float))[0];
    r.b[2] = (msg->payload+sizeof(uint64_t)+sizeof(float)+sizeof(float)+sizeof(float))[1];
    r.b[1] = (msg->payload+sizeof(uint64_t)+sizeof(float)+sizeof(float)+sizeof(float))[2];
    r.b[0] = (msg->payload+sizeof(uint64_t)+sizeof(float)+sizeof(float)+sizeof(float))[3];
    return (float)r.f;
}

/**
 * @brief Decode a roll_pitch_yaw_speed_thrust_setpoint message into a struct
 *
 * @param msg The message to decode
 * @param roll_pitch_yaw_speed_thrust_setpoint C-struct to decode the message contents into
 */
static inline void mavlink_msg_roll_pitch_yaw_speed_thrust_setpoint_decode(const mavlink_message_t* msg, mavlink_roll_pitch_yaw_speed_thrust_setpoint_t* roll_pitch_yaw_speed_thrust_setpoint)
{
    roll_pitch_yaw_speed_thrust_setpoint->time_us = mavlink_msg_roll_pitch_yaw_speed_thrust_setpoint_get_time_us(msg);
    roll_pitch_yaw_speed_thrust_setpoint->roll_speed = mavlink_msg_roll_pitch_yaw_speed_thrust_setpoint_get_roll_speed(msg);
    roll_pitch_yaw_speed_thrust_setpoint->pitch_speed = mavlink_msg_roll_pitch_yaw_speed_thrust_setpoint_get_pitch_speed(msg);
    roll_pitch_yaw_speed_thrust_setpoint->yaw_speed = mavlink_msg_roll_pitch_yaw_speed_thrust_setpoint_get_yaw_speed(msg);
    roll_pitch_yaw_speed_thrust_setpoint->thrust = mavlink_msg_roll_pitch_yaw_speed_thrust_setpoint_get_thrust(msg);
}
