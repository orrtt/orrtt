#ifndef LIBORRTT_PACKET_HPP_INCLUDED
#define LIBORRTT_PACKET_HPP_INCLUDED

#include "archiver.hpp"
#include <cstdint>
#include <array>

namespace orrtt
{
  constexpr size_t MAX_PACKET_SIZE = 576;

  enum type
  {
    ORT_SYN,
    ORT_ACK,
    ORT_FIN,
  };

  struct header
  {
    std::uint16_t type:4;
    std::uint16_t size:12;
    std::uint16_t sid;
    std::uint16_t serial;
    std::uint16_t checksum;
  };


  class packet
  {
  public:
    using size_type = std::uint16_t;

    packet();

    template<typename Archiver>
      friend void serialize(Archiver &archiver, packet &pkt)
      {
        archiver & pkt.m_header;

      }

  private:
    static constexpr size_t MAX_PAYLOAD_SIZE = MAX_PACKET_SIZE - sizeof(header);


    header m_header;
    unsigned char m_payload[MAX_PAYLOAD_SIZE];
    size_type size;
  };

  template<typename Archiver>
  void serialize(Archiver &archiver, const header &header)
  {

    std::uint8_t x = ((header.type << 4) & 0xF0) + ((header.size & 0xF00) >> 8);
    std::uint8_t y = header.size & 0xFF;

    archiver & x;
    archiver & y;
    archiver & header.sid;
    archiver & header.serial;
    archiver & header.checksum;
  }

  template<typename Archiver>
  void serialize(const Archiver &archiver, header &header)
  {

    std::uint8_t x; //= ((header.type << 4) & 0xF0) + ((header.size & 0xF00) >> 8);
    std::uint8_t y; //= header.size & 0xFF;

    archiver & x;
    archiver & y;

    header.type = (x & 0xF0) >> 4;
    header.size = x & 0x0F;
    header.size <<= 8;
    header.size += y;

    archiver & header.sid;
    archiver & header.serial;
    archiver & header.checksum;

  }
}

#endif
