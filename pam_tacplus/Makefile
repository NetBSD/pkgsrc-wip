# $NetBSD: Makefile,v 1.3 2009/03/31 21:30:33 pettai Exp $
#

DISTNAME=	pam_tacplus-1.2.11
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tacplus/}

MAINTAINER=	pettai@nordu.net
HOMEPAGE=	http://tacplus.sourceforge.net/
COMMENT=	TACACS+ client library and PAM module

WRKSRC=	${WRKDIR}/tacplus
EGDIR= ${PREFIX}/share/examples/pam_tacplus

PKG_DESTDIR_SUPPORT=	user-destdir

SUBST_CLASSES+=         paths
SUBST_FILES.paths=      ${WRKSRC}/Makefile
SUBST_STAGE.paths=      post-patch
SUBST_SED.paths=        -e 's,@PREFIX@,${PREFIX},'

INSTALLATION_DIRS=	lib/security ${EGDIR}

post-install:
	${INSTALL} ${WRKSRC}/sample.pam ${DESTDIR}${EGDIR}/sample.pam

.include "../../mk/bsd.pkg.mk"
