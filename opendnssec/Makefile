# $NetBSD: Makefile,v 1.5 2009/09/29 15:10:19 pettai Exp $
#

DISTNAME=	opendnssec-${RCVERSION}
CATEGORIES=	security
MASTER_SITES=	# not defined

MAINTAINER=	pettai@nordu.net
HOMEPAGE=	http://www.opendnssec.org/
COMMENT=	OSS for a fast and easy DNSSEC deployment
LICENSE=	iis-license

LICENSE_FILE=	${FILESDIR}/iis-license

USE_TOOLS+=     aclocal autoconf automake autoheader gmake gm4 perl
USE_LIBTOOL=	yes

SVN_REPOSITORIES=	opendnssec
SVN_ROOT.opendnssec=	http://svn.opendnssec.org/tags/OpenDNSSEC-${RCVERSION}
SVN_MODULE.opendnssec=	OpenDNSSEC
RCVERSION=		1.0a5
NO_CHECKSUM=		yes

.include "options.mk"

PKG_JVMS_ACCEPTED=	sun-jdk6 sun-jdk15 sun-jdk14

# XXX: Others might work
#ONLY_FOR_PLATFORM=	NetBSD-*-* Linux-*-*

PKG_DESTDIR_SUPPORT=    user-destdir
PKG_INSTALLATION_TYPES= overwrite pkgviews

BUILD_DEFS+=	VARBASE

USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}/opendnssec
CONFIGURE_ENV+=		F77=${FALSE:Q}

WRKSRC=			${WRKDIR}/OpenDNSSEC

CXXFLAGS.NetBSD+=	-D_NETBSD_SOURCE

pre-configure:
	${CHMOD} u+x ${WRKSRC}/autogen.sh
	cd ${WRKSRC} && ./autogen.sh

.include "../../lang/python/application.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../net/ldns/buildlink3.mk"
.include "../../devel/cunit/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../wip/mk/svn-package.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
