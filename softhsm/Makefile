# $NetBSD: Makefile,v 1.4 2009/09/29 14:53:34 pettai Exp $
#

DISTNAME=	softhsm-${RCVERSION}
CATEGORIES=	security
MASTER_SITES=	# not defined

MAINTAINER=	pettai@nordu.net
HOMEPAGE=	http://www.opendnssec.se/wiki/SoftHSM/
COMMENT=	Cryptographic store accessible through a PKCS#11 interface
LICENSE=	iis-license

LICENSE_FILE=	${FILESDIR}/iis-license

USE_TOOLS+=     aclocal autoconf automake autoheader gmake gm4
USE_LIBTOOL=	yes

SVN_REPOSITORIES=	softhsm
SVN_ROOT.softhsm=	http://svn.opendnssec.org/tags/softHSM-${RCVERSION}/
SVN_MODULE.softhsm=	softHSM
RCVERSION=		1.0.0-RC3
NO_CHECKSUM=		yes

PKG_DESTDIR_SUPPORT=    user-destdir
PKG_INSTALLATION_TYPES= overwrite pkgviews

BUILD_DEFS+=	VARBASE

USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}/softhsm
CONFIGURE_ENV+=		F77=${FALSE:Q}

WRKSRC=			${WRKDIR}/softHSM

CXXFLAGS.NetBSD+=	-D_NETBSD_SOURCE

pre-configure:
	${CHMOD} u+x ${WRKSRC}/autogen.sh
	cd ${WRKSRC} && ./autogen.sh

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../wip/botan/buildlink3.mk"
.include "../../wip/mk/svn-package.mk"
.include "../../mk/bsd.pkg.mk"
