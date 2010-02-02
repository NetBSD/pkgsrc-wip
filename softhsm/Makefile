# $NetBSD: Makefile,v 1.16 2010/02/02 14:11:05 pettai Exp $
#

DISTNAME=	softhsm-${VERSION}
#PKGNAME=	${DISTNAME:S/${VERSION}/${RCVERSION}/}
CATEGORIES=	security
MASTER_SITES=	http://www.opendnssec.org/files/source/

MAINTAINER=	pettai@nordu.net
HOMEPAGE=	http://www.opendnssec.se/wiki/SoftHSM/
COMMENT=	Cryptographic store accessible through a PKCS#11 interface
LICENSE=	iis-license

LICENSE_FILE=	${FILESDIR}/iis-license

#USE_TOOLS+=     aclocal autoconf automake autoheader gmake gm4
USE_LIBTOOL=	yes

#SVN_REPOSITORIES=	softhsm
#SVN_ROOT.softhsm=	http://svn.opendnssec.org/tags/softHSM-${RCVERSION}/
#SVN_MODULE.softhsm=	softHSM
VERSION=		1.1.3
#RCVERSION=		${VERSION:S/-RC/rc/}
#NO_CHECKSUM=		yes

PKG_DESTDIR_SUPPORT=    user-destdir
#PKG_INSTALLATION_TYPES= overwrite pkgviews

BUILD_DEFS+=	VARBASE

USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}

#WRKSRC=		${WRKDIR}/softHSM
EGDIR=			${PREFIX}/share/examples/softhsm

SUBST_CLASSES+=         paths
SUBST_FILES.paths=      ${WRKSRC}/Makefile.in
SUBST_STAGE.paths=      post-patch
SUBST_SED.paths=        -e 's,@EGDIR@,${EGDIR},'

CXXFLAGS.NetBSD+=	-D_NETBSD_SOURCE

CONF_FILES=		${EGDIR}/softhsm.conf ${PKG_SYSCONFDIR}/softhsm.conf

INSTALLATION_DIRS=	${EGDIR} ${VARBASE}/softhsm
INSTALLATION_DIRS+=	etc bin lib

.include "options.mk"

#pre-configure:
#	${CHMOD} u+x ${WRKSRC}/autogen.sh
#	cd ${WRKSRC} && ./autogen.sh

pre-install:
	${INSTALL_DATA} ${WRKSRC}/softhsm.conf ${DESTDIR}${EGDIR}

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../security/botan/buildlink3.mk"
#.include "../../wip/mk/svn-package.mk"
.include "../../mk/bsd.pkg.mk"
