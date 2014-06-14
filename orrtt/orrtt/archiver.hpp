#ifndef LIBORRTT_ARCHIVER_HPP_INCLUDED
#define LIBORRTT_ARCHIVER_HPP_INCLUDED

#include <vector>
#include <memory>
#include <string>

namespace orrtt
{

  template<typename Archiver, typename T>
  void serialize(Archiver &archiver, T &val)
  {
    T::serialize(archiver, val);
  }

  class input_archiver
  {
  public:
    input_archiver(size_t maxsize);

    template<typename T>
    friend input_archiver & operator & (input_archiver &archiver, T &val)
    {
      serialize(archiver, val);
      return archiver;
    }


    friend input_archiver & operator & (input_archiver &, std::int8_t);

    friend input_archiver & operator & (input_archiver &, std::uint8_t);

    friend input_archiver & operator & (input_archiver &, std::int16_t);

    friend input_archiver & operator & (input_archiver &, std::uint16_t);

    friend input_archiver & operator & (input_archiver &, std::int32_t);

    friend input_archiver & operator & (input_archiver &, std::uint32_t);

    friend input_archiver & operator & (input_archiver &, std::int64_t);

    friend input_archiver & operator & (input_archiver &, std::uint64_t);

    friend input_archiver & operator & (input_archiver &, const char *);

    friend input_archiver & operator & (input_archiver &, const std::string &);

  private:
    const std::size_t m_max_size;
    std::size_t m_size;
    std::unique_ptr<std::uint8_t[]> m_data;
  };


  class output_archiver
  {
  public:
    output_archiver(std::uint8_t data[], size_t maxsize);

    output_archiver(std::unique_ptr<std::uint8_t[]> data, size_t maxsize);

    friend input_archiver & operator & (input_archiver &, std::int8_t);

    friend input_archiver & operator & (input_archiver &, std::uint8_t);

    friend input_archiver & operator & (input_archiver &, std::int16_t);

    friend input_archiver & operator & (input_archiver &, std::uint16_t);

    friend input_archiver & operator & (input_archiver &, std::int32_t);

    friend input_archiver & operator & (input_archiver &, std::uint32_t);

    friend input_archiver & operator & (input_archiver &, std::int64_t);

    friend input_archiver & operator & (input_archiver &, std::uint64_t);

    friend input_archiver & operator & (input_archiver &, const char *);

    friend input_archiver & operator & (input_archiver &, const std::string &);

  private:
    const std::size_t m_max_size;
    std::size_t m_size;
    std::unique_ptr<std::uint8_t[]> m_data;
  };

}

#endif

