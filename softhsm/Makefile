# $NetBSD: Makefile,v 1.10 2009/10/24 20:52:44 pettai Exp $
#

DISTNAME=	softhsm-${VERSION}
PKGNAME=	${DISTNAME:S/${VERSION}/${RCVERSION}/}
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
VERSION=		1.0.0
RCVERSION=		${VERSION:S/-RC/rc/}
NO_CHECKSUM=		yes

PKG_DESTDIR_SUPPORT=    user-destdir
PKG_INSTALLATION_TYPES= overwrite pkgviews

BUILD_DEFS+=	VARBASE

USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}

PLIST_OPSYS?=		${PKGDIR}/PLIST.${LOWER_OPSYS:C/([.0-9]*)$//}
.if exists(${PLIST_OPSYS})
PLIST_SHLIB=		${PLIST_OPSYS}
.else
PLIST_SHLIB=		${PKGDIR}/PLIST.shlib
.endif
PLIST_SRC=		${PLIST_SHLIB}
PLIST_SRC+=		${PKGDIR}/PLIST.common
PLIST_SUBST+=		SHLIB_VERSION=${RCVERSION:C/[^0-9]*$//}

WRKSRC=			${WRKDIR}/softHSM
EGDIR=			${PREFIX}/share/examples/softhsm

CXXFLAGS.NetBSD+=	-D_NETBSD_SOURCE

CONF_FILES=		${EGDIR}/softhsm.conf ${PKG_SYSCONFDIR}/softhsm.conf

INSTALLATION_DIRS=	${EGDIR} ${VARBASE}/softhsm

pre-configure:
	${CHMOD} u+x ${WRKSRC}/autogen.sh
	cd ${WRKSRC} && ./autogen.sh

pre-install:
	${INSTALL_DATA} ${WRKSRC}/softhsm.conf ${DESTDIR}${EGDIR}

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../security/botan/buildlink3.mk"
.include "../../wip/mk/svn-package.mk"
.include "../../mk/bsd.pkg.mk"
