#include <boost/asio.hpp>
#include <array>
#include <memory>

namespace orrtt
{

  namespace asio = boost::asio;
  namespace system = boost::system;

  class tunnel_node;

  class directory_server
  {
  public:
    directory_server(asio::io_service &iosvc);
    ~directory_server() = default;


    std::uint16_t register_tunnel(std::shared_ptr<tunnel_node>);
  private:

    void start_service();

    void handle_request(const system::error_code &ec, size_t size);


    asio::ip::udp::socket m_socket;
    std::map<std::uint16_t, std::shared_ptr<tunnel_node>> m_tunnel_directory;
    std::array<char, 1400> m_buffer;
    asio::ip::udp::endpoint m_current_client;

  };
}
