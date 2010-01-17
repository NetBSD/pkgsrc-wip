# $NetBSD: Makefile,v 1.4 2010/01/17 12:03:23 thomasklausner Exp $
#

DISTNAME=	cfengine-3.0.2
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.cfengine.org/tarballs/

MAINTAINER=	msporleder@gmail.com
HOMEPAGE=	http://www.cfengine.org/
COMMENT=	Tool for automating system administration
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=          YES
USE_TOOLS+=             flex yacc gmake
USE_LIBTOOL=		YES
USE_LANGUAGES= c c++
PKG_DESTDIR_SUPPORT=    user-destdir
BUILDLINK_TRANSFORM+=l:db:db4
CONFIGURE_ARGS+=        --with-berkeleydb=${BUILDLINK_PREFIX.db4:Q}
CONFIGURE_ARGS+=        --with-openssl=${BUILDLINK_PREFIX.openssl:Q}
CONFIGURE_ARGS+=        --with-pcre=${BUILDLINK_PREFIX.pcre:Q}

EGDIR=                  /var/${PKGBASE}
CONF_FILES+=            ${PREFIX/share/${PKGBASE}/failsafe.cf ${EGDIR}/failsafe.cf
CONF_FILES+=            ${PREFIX}/share/${PKGBASE}/library.cf ${EGDIR}/library.cf
CONF_FILES+=            ${PREFIX}/share/${PKGBASE}/promises.cf ${EGDIR}/promises.cf
CONF_FILES+=            ${PREFIX}/share/${PKGBASE}/site.cf ${EGDIR}/site.cf
CONF_FILES+=            ${PREFIX}/share/${PKGBASE}/update.cf ${EGDIR}/update.cf
INSTALL_MAKE_FLAGS+=    ${MAKE_FLAGS} sysconfdir=${EGDIR:Q}

.include "../../databases/db4/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
