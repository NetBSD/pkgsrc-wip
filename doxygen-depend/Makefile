# $NetBSD: Makefile,v 1.6 2015/02/10 08:56:25 makoto Exp $
# $Id: Makefile,v 1.6 2015/02/10 08:56:25 makoto Exp $

DISTNAME=	doxygen-dependent-1.01
CATEGORIES=	meta-pkgs
LICENSE=	generic-nonlicense

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Collection of dependent pkgs to check doxygen update

META_PACKAGE=	YES

.include "../../mk/bsd.pkg.mk"

#EPENDS+=	dar-[0-9]*:../../archivers/dar		# disabled by configure
DEPENDS+=	darkice-[0-9]*:../../audio/darkice	# not known yet
DEPENDS+=	libfishsound-[0-9]*:../../audio/libfishsound
DEPENDS+=	libopus-[0-9]*:../../audio/libopus
DEPENDS+=	libvorbis-[0-9]*:../../audio/libvorbis
DEPENDS+=	sphinx3-[0-9]*:../../audio/sphinx3
DEPENDS+=	twolame-[0-9]*:../../audio/twolame

DEPENDS+=	nelma-[0-9]*:../../cad/boolean
DEPENDS+=	nelma-[0-9]*:../../cad/nelma

#EPENDS+=	meanwhile-[0-9]*:../../chat/meanwhile	# disabled by configure

#EPENDS+=	gammu-[0-9]*:../../comms/gammu		# used to be BUILD_DEPENDS
DEPENDS+=	asterisk-[0-9]*:../../comms/asterisk
DEPENDS+=	asterisk-1.8.[0-9]*:../../comms/asterisk18

DEPENDS+=	openobex-[0-9]*:../../comms/openobex	# YES explicit
#EPENDS+=	libcdr-[0-9]*:../../converters/libcdr	# disabled by configure
DEPENDS+=	libvisio-[0-9]*:../../converters/libvisio # YES (as of 201501)
DEPENDS+=	avr-libc-[0-9]*:../../cross/avr-libc
DEPENDS+=	libpqxx-doc-[0-9]*:../../databases/libpqxx-doc # unknown

DEPENDS+=	freetds-[0-9]*:../../databases/freetds
DEPENDS+=	kyotocabinet-[0-9]*:../../databases/kyotocabinet
DEPENDS+=	libpqxx-doc-[0-9]*:../../databases/libpqxx-doc
DEPENDS+=	qdbm-plus-[0-9]*:../../databases/qdbm-plus
DEPENDS+=	qore-mysql-module-[0-9]*:../../databases/qore-mysql-module
DEPENDS+=	qore-openldap-module-[0-9]*:../../databases/qore-openldap-module
DEPENDS+=	qore-pgsql-module-[0-9]*:../../databases/qore-pgsql-module
DEPENDS+=	sqlrelay-[0-9]*:../../databases/sqlrelay

DEPENDS+=	bison-[0-9]*:../../devel/bison		# unknown
DEPENDS+=	cppunit-[0-9]*:../../devel/cppunit	# unknown
DEPENDS+=	kdevelop-base-[0-9]*:../../devel/kdevelop-base # YES
#EPENDS+=	log4cxx-[0-9]*:../../devel/log4cxx	# disabled by configure
#EPENDS+=	log4shib-[0-9]*:../../devel/log4shib	# disabled by configure
#EPENDS+=	lutok-[0-9]*:../../devel/lutok		# disabled by configure
DEPENDS+=	qof-[0-9]*:../../devel/qof		# YES

DEPENDS+=	simulavr-[0-9]*:../../emulators/simulavr # YES
DEPENDS+=	yabause-[0-9]*:../../emulators/yabause	# unknown

DEPENDS+=	aqsis-[0-9]*:../../graphics/aqsis	# unknown
DEPENDS+=	gnuradio-doxygen-[0-9]*:../../ham/gnuradio-doxygen # YES
DEPENDS+=	ibus-qt-[0-9]*:../../inputmethod/ibus-qt # TOOLS_NOOP= doxygen

.if 0
DEPENDS+=	gcc44-[0-9]*:../../lang/gcc44
DEPENDS+=	gcc45-[0-9]*:../../lang/gcc45
DEPENDS+=	gcc46-[0-9]*:../../lang/gcc46
.endif

#EPENDS+=	blitz++-[0-9]*:../../math/blitz++	# disabled by configure
DEPENDS+=	libcarddav-[0-9]*:../../misc/libcarddav	# unknown
DEPENDS+=	libtheora-docs-[0-9]*:../../multimedia/libtheora-docs # YES
#EPENDS+=	libvdpau-[0-9]*:../../multimedia/libvdpau # Probably NO

#EPENDS+=	avahi-[0-9]*:../../net/avahi		# disabled by configure
#DEPENDS+=	libtrace-[0-9]*:../../net/libtrace	# disabled by CONFIGURE_ENV
DEPENDS+=	libktorrent-[0-9]*:../../net/libktorrent

#EPENDS+=	opensaml-[0-9]*:../../security/opensaml	# disabled by configure

DEPENDS+=	dbus-[0-9]*:../../sysutils/dbus		# YES
#EPENDS+=	dbus-glib-[0-9]*:../../sysutils/dbus-glib	# disabled by configure
#EPENDS+=	gnome-vfsmm-[0-9]*:../../sysutils/gnome-vfsmm	# NO

#EPENDS+=	xmltooling-[0-9]*:../../textproc/xmltooling	# disabled by configure
DEPENDS+=	awesome-[0-9]*:../../wm/awesome
DEPENDS+=	tidy-[0-9]*:../../www/tidy		# YES

#EPENDS+=	gnome-mag-[0-9]*:../../x11/gnome-mag	# disabled by SUBST
DEPENDS+=	kdelibdocs-[0-9]*:../../x11/kdelibdocs3	# YES
#EPENDS+=	libxcb-[0-9]*:../../x11/libxcb		# disabled by configure
#DEPENDS+=	razorqt-[0-9]*:../../x11/razor-qt	# removed ?
