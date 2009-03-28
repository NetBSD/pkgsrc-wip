# $NetBSD: Makefile,v 1.2 2009/03/28 17:08:05 pettai Exp $
#

DISTNAME=	pam_tacplus-1.2.10
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tacplus/}

MAINTAINER=	pettai@nordu.net
HOMEPAGE=	http://tacplus.sourceforge.net/
COMMENT=	TACACS+ client library and PAM module

WRKSRC=	${WRKDIR}/pam_tacplus

PKG_DESTDIR_SUPPORT=	user-destdir

SUBST_CLASSES+=         paths
SUBST_FILES.paths=      ${WRKSRC}/Makefile
SUBST_STAGE.paths=      post-patch
SUBST_SED.paths=        -e 's,@PREFIX@,${PREFIX},'

#USE_TOOLS+=		gmake

MAKE_DIRS+=             ${DESTDIR}${PREFIX}/lib/security

.include "../../mk/bsd.pkg.mk"
