

bin_PROGRAMS=orrtt_server

orrtt_server_SOURCES=orrtt.cpp\
					 directory_server.hpp\
					 directory_server.cpp

orrtt_server_CPPFLAGS=$(BOOST_CPPFLAGS) -I$(srcdir)/../orrtt
orrtt_server_LDADD=$(BOOST_ASIO_LIBS) ../orrtt/liborrtt.la

