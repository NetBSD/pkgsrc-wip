# $NetBSD: Makefile,v 1.5 2006/03/09 15:24:09 ghen Exp $

DISTNAME=	DarwinStreamingSrvr${DSS_VERSION}
PKGNAME=	DarwinStreamingServer-${DSS_VERSION}
CATEGORIES=	net
MASTER_SITES=	http://www.opensource.apple.com/projects/streaming/release/
DISTFILES=	DarwinStreamingSrvr${DSS_VERSION}-Source.tar

MAINTAINER=	eggert@macvaerk.dtu.dk
HOMEPAGE=	http://developer.apple.com/darwin/projects/streaming/
COMMENT=	Open source version of Apple's QuickTime Streaming Server technology

WRKSRC=		${WRKDIR}/DarwinStreamingSrvr${DSS_VERSION}-Source

DSS_VERSION=	5.5

PKG_INSTALLATION_TYPES=	overwrite pkgviews

REPLACE_INTERPRETER+=	bash
_REPLACE.bash.old=	*/bin/bash
_REPLACE.bash.new=	${SH}
_REPLACE_FILES.bash=	Install

RESTRICTED=		Under APSL (see http://www.opensource.apple.com/apsl/).
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

#ONLY_FOR_PLATFORM=      FreeBSD-*-* NetBSD-*-* Linux-*-* SunOS-*-* IRIX-*-* IRIX64-*-*

INTERACTIVE_STAGE=	fetch build

_FETCH_MESSAGE=	\
	${ECHO} "======================================================="; \
	${ECHO} "  Darwin Streaming Server is available as a free";	   \
	${ECHO} "  download under the APSL. Downloading the source";	   \
	${ECHO} "  code components requires APSL registration.";	   \
	${ECHO} "  You should manual-fetch the source code to";		   \
	${ECHO} "  ${DISTDIR}/${DISTFILES}";				   \
	${ECHO} "  from";						   \
	${ECHO} "  <${MASTER_SITES}${DISTFILES}>";			   \
	${ECHO} "======================================================="; \
	${FALSE}

LICENSE=	apple-public-source-license

REPLACE_PERL+= \
	WebAdmin/perlpath.pl				\
	WebAdmin/src/streamingadminserver.pl		\
	WebAdmin/WebAdminHtml/adminprotocol-lib.pl	\
	WebAdmin/WebAdminHtml/broadcaster_lib.pl	\
	WebAdmin/WebAdminHtml/cgi-lib.pl		\
	WebAdmin/WebAdminHtml/MapUTF.pl			\
	WebAdmin/WebAdminHtml/password-utils.pl		\
	WebAdmin/WebAdminHtml/playlist-lib.pl		\
	WebAdmin/WebAdminHtml/relayxmlparser.pl		\
	WebAdmin/WebAdminHtml/startplaylists.pl		\
	WebAdmin/WebAdminHtml/tag_formats.pl		\
	WebAdmin/WebAdminHtml/tag_types.pl		\
	WebAdmin/WebAdminHtml/tag_vals.pl

SUBST_CLASSES+=		dss-conf
SUBST_STAGE.dss-conf=	post-configure
SUBST_FILES.dss-conf=	WebAdmin/streamingadminserver.conf
SUBST_SED.dss-conf=	\
	-e "s|/Library/QuickTimeStreaming/AdminHtml|${PREFIX}/share/streaming/AdminHtml|" \
	-e "s|/Library/QuickTimeStreaming/Playlists|${PREFIX}/share/streaming/playlists|" \
	-e "s|host=foo.bar.com|host=`hostname`|"	\
	-e "s|/usr/sbin/QuickTimeStreamingServer|${PREFIX}/sbin/DarwinStreamingServer|" \
	-e "s|/Library/QuickTimeStreaming/Logs|${VARBASE}/log/streaming|"

SUBST_CLASSES+=		dss
SUBST_STAGE.dss=	post-configure
SUBST_FILES.dss=	\
	Documentation/readme.txt			\
	StreamingProxy.tproj/StreamingProxy.html	\
	WebAdmin/NetSSLeay/SSLeay.pm			\
	WebAdmin/src/streamingadminserver.pl		\
	WebAdmin/streamingadminserver_Darwin.conf	\
	qtaccess					\
	streamingserver.xml-POSIX			\
	defaultPaths.h					\
	Install
SUBST_SED.dss=		\
	-e "s|/usr/local/movies|${PREFIX}/share/streaming/movies|"	\
	-e "s|/etc/streaming|${PKG_SYSCONFDIR}/streaming|"		\
	-e "s|/usr/local|${PREFIX}|"					\
	-e "s|\$$INSTALLROOT/var/streaming/AdminHtml|${PREFIX}/share/streaming/AdminHtml|" \
	-e "s|/var/streaming/playlists|${PREFIX}/share/streaming/playlists|" \
	-e "s|/var/streaming/logs|${VARBASE}/log/streaming|"

CONF_FILES=	${PKG_SYSCONFDIR:Q}/streaming/qtgroups-dist ${PKG_SYSCONFDIR:Q}/streaming/qtgroups
CONF_FILES+=	${PKG_SYSCONFDIR:Q}/streaming/qtusers-dist ${PKG_SYSCONFDIR:Q}/streaming/qtusers
CONF_FILES+=	${PKG_SYSCONFDIR:Q}/streaming/relayconfig.xml-Sample ${PKG_SYSCONFDIR:Q}/streaming/relayconfig.xml
CONF_FILES+=	${PKG_SYSCONFDIR:Q}/streaming/streamingserver.xml-dist ${PKG_SYSCONFDIR:Q}/streaming/streamingserver.xml

post-extract:
	${RM} -rf ${WRKSRC:Q}/dssPackageMetaData ${WRKSRC:Q}/pubPackageMetaData \
		${WRKSRC:Q}/qtssPackageMetaData

do-configure:
	# nothing

do-build:
	# This line does not work:
	# cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${WRKSRC}/Buildit
	# so we need to do things manually...
	[ -f ${WRKSRC:Q}/QTFileTools/QTTrackInfo.tproj/QTTrackInfo.o ] || (  \
	${ECHO} "======================================================="; \
	${ECHO} " To build, please";					   \
	${ECHO} "   cd ${WRKSRC}";					   \
	${ECHO} "   ./Buildit";						   \
	${ECHO} " then continue the pkgsrc build.";			   \
	${ECHO} "======================================================="; \
	${FALSE}							   \
	)

do-install:
	cd ${WRKSRC:Q}; ${SETENV} ${MAKE_ENV} ${WRKSRC:Q}/Install

# To Do:
# - copy documentation into ${PREFIX}/share/doc/${PKGBASE}
# - have user name of dss specified here
# - have root dir of server specified here

.include "../../mk/bsd.pkg.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"

MAKE_ENV+=	PKGSRCMAKE=${MAKE:Q}
