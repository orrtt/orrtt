
#include "directory_server.hpp"
#include <orrtt/packet.hpp>

namespace orrtt
{
  using namespace asio;
  using namespace asio::ip;

  directory_server::directory_server(io_service &iosvc)
    : m_socket(iosvc, udp::endpoint(udp::v4(), 1989))
      , m_tunnel_directory()
  {
    start_service();
  }


  void directory_server::start_service()
  {
    m_socket.async_receive_from(
        asio::buffer(m_buffer.data(), m_buffer.size()),
        m_current_client,
        std::bind(&directory_server::handle_request, this,
          std::placeholders::_1,
          std::placeholders::_2));
  }

  void directory_server::handle_request(
      const system::error_code &ec,
      size_t size)
  {

  }
}
