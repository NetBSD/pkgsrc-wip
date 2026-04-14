# $NetBSD: Makefile,v 1.7 2024/06/28 13:01:31 ktnb Exp $

DISTNAME=		s-nail-v14.10.0-alpha
PKGNAME=		${DISTNAME:S/v//:S/-alpha//}
CATEGORIES=		mail
MASTER_SITES=		https://www.sdaoden.eu/downloads/
EXTRACT_SUFX=        .tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.sdaoden.eu/code.html
COMMENT=		BSD mail utility with MIME extensions
LICENSE=		original-bsd AND osl AND mpl-1.1

MAKE_FILE=		makefile

EGDIR=			${PREFIX}/share/examples/${PKGBASE}
MAKE_FLAGS+=		VAL_PREFIX=${PREFIX}
MAKE_FLAGS+=		VAL_MANDIR=${PREFIX}/${PKGMANDIR}
MAKE_FLAGS+=		OPT_AUTOCC=no
INSTALL_MAKE_FLAGS+=	PKGBASE=${PKGBASE}

INSTALLATION_DIRS+=	share/examples/${PKGBASE}

REPLACE_PYTHON+=	src/oauth-helper.py

CONF_FILES=		${EGDIR}/s-nail.rc ${PKG_SYSCONFDIR}/s-nail.rc

post-install:
	${MV} ${DESTDIR}${PKG_SYSCONFDIR}/s-nail.rc ${DESTDIR}${EGDIR}/s-nail.rc

.include "../../devel/libidn2/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
