# $NetBSD: Makefile,v 1.9 2009/10/11 19:21:16 pettai Exp $
#

DISTNAME=	opendnssec-${VERSION}
CATEGORIES=	net security
MASTER_SITES=	# not defined

MAINTAINER=	pettai@nordu.net
HOMEPAGE=	http://www.opendnssec.org/
COMMENT=	OSS for a fast and easy DNSSEC deployment
LICENSE=	iis-license

DEPENDS+=	${PYPKGPREFIX}-4Suite:../../wip/py-4Suite

LICENSE_FILE=	${FILESDIR}/iis-license

USE_TOOLS+=     aclocal autoconf automake autoheader gmake gm4 perl
USE_JAVA=	no
USE_LIBTOOL=	yes

SVN_REPOSITORIES=	opendnssec
SVN_ROOT.opendnssec=	http://svn.opendnssec.org/tags/OpenDNSSEC-${VERSION}
SVN_MODULE.opendnssec=	OpenDNSSEC
VERSION=		1.0.0b2
NO_CHECKSUM=		yes

.include "options.mk"

# XXX: Others might work
#ONLY_FOR_PLATFORM=	NetBSD-*-* Darwin-*-*

PKG_DESTDIR_SUPPORT=    user-destdir
PKG_INSTALLATION_TYPES= overwrite pkgviews

BUILD_DEFS+=	VARBASE

USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}

WRKSRC=			${WRKDIR}/OpenDNSSEC

CXXFLAGS.NetBSD+=	-D_NETBSD_SOURCE

.if ${OPSYS} == "NetBSD" 
#PKG_JVMS_ACCEPTED=	sun-jdk6 sun-jdk15 sun-jdk14
.include "../../mk/java-vm.mk"
.endif

pre-configure:
	${CHMOD} u+x ${WRKSRC}/autogen.sh
	cd ${WRKSRC} && ./autogen.sh

.include "../../lang/python/application.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../net/ldns/buildlink3.mk"
.include "../../devel/cunit/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../wip/mk/svn-package.mk"
.include "../../mk/bsd.pkg.mk"
