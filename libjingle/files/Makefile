CPPFLAGS=	-I../.. -I..			\
		-DHAMMER_TIME=1 		\
		-DLOGGING=1			\
		-DFEATURE_ENABLE_SSL 		\
		-DFEATURE_ENABLE_VOICEMAIL 	\
		-DFEATURE_ENABLE_PSTN 		\
		-DHAVE_SRTP			\
		-DHASHNAMESPACE=__gnu_cxx	\
		-DHASH_NAMESPACE=__gnu_cxx	\
    		-DPOSIX				\
		-DBSD				\
		-DDISABLE_DYNAMIC_CAST		\
    		-DHAVE_OPENSSL_SSL_H=1		\
    		-D_REENTRANT
CFLAGS=		-Wall -Werror -Wno-switch -fno-exceptions -fvisibility=hidden -gdwarf-2
CXXFLAGS=	-Wno-non-virtual-dtor -Wno-ctor-dtor-privacy -fno-rtti
LTCOMP=		libtool --mode=compile
CXX=		${LTCOMP} c++
CC=		${LTCOMP} --tag=CC cc

#SRCS=		$(wildcard *.cc)
#SRCS=		$(shell find . \( -name "*.cc" -a \! -name "*unittest*" -a \! -name "mac*" -a \! -name "win32*" \))
SRCS=		stringutils.cc latebindingsymboltable.cc linux.cc unixfilesystem.cc		\
		opensslidentity.cc opensslstreamadapter.cc sslidentity.cc sslstreamadapter.cc	\
		asyncfile.cc asynchttprequest.cc asyncsocket.cc asynctcpsocket.cc		\
		asyncudpsocket.cc autodetectproxy.cc base64.cc basicpacketsocketfactory.cc	\
		bytebuffer.cc checks.cc common.cc diskcache.cc event.cc fileutils.cc		\
		firewallsocketserver.cc flags.cc helpers.cc host.cc httpbase.cc httpclient.cc	\
		httpcommon.cc httprequest.cc logging.cc messagehandler.cc messagequeue.cc	\
		nethelpers.cc network.cc openssladapter.cc pathutils.cc physicalsocketserver.cc	\
		proxydetect.cc proxyinfo.cc ratetracker.cc signalthread.cc socketadapters.cc	\
		socketaddress.cc socketaddresspair.cc socketpool.cc socketstream.cc		\
		ssladapter.cc sslsocketfactory.cc stream.cc stringdigest.cc stringencode.cc	\
		task.cc taskparent.cc taskrunner.cc thread.cc time.cc urlencode.cc worker.cc	\
		httpserver.cc bandwidthsmoother.cc cpuid.cc cpumonitor.cc filelock.cc		\
		ipaddress.cc multipart.cc natserver.cc natsocketfactory.cc nattypes.cc		\
		optionsfile.cc proxyserver.cc sharedexclusivelock.cc systeminfo.cc		\
		testclient.cc timeutils.cc timing.cc versionparsing.cc virtualsocketserver.cc

### TODO: figure out what's wrong with the following files: #############################
# json.cc: 	requires json-cpp which is not present in-tree nor packaged but
# 		also not mentioned in README and not used elsewhere.
# asyncpacketsocket.cc:
# 		Windows only? How does scons figure out which files to build
# 		for which platform?
#########################################################################################

OBJS=		$(SRCS:.cc=.o) md5c.o

all: $(OBJS)

.cc.o:
	@${CXX} ${CPPFLAGS} ${CXXFLAGS} -c $< -o $@
.c.o:
	@${CC} ${CPPFLAGS} ${CFLAGS} -c $< -o $@
clean:
	rm -f *.o *.lo
