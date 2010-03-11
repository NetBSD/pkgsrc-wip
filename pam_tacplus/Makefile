# $NetBSD: Makefile,v 1.4 2010/03/11 12:33:27 pettai Exp $
#

DISTNAME=	pam_tacplus-1.2.11
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tacplus/}

MAINTAINER=	pettai@nordu.net
HOMEPAGE=	http://tacplus.sourceforge.net/
COMMENT=	TACACS+ client library and PAM module
#LICENSE=

WRKSRC=	${WRKDIR}/tacplus
EGDIR= ${PREFIX}/share/examples/pam_tacplus

PKG_DESTDIR_SUPPORT=	user-destdir

SUBST_CLASSES+=         paths
SUBST_FILES.paths=      ${WRKSRC}/Makefile
SUBST_STAGE.paths=      post-patch
SUBST_SED.paths=        -e 's,@PREFIX@,${PREFIX},'

INSTALLATION_DIRS=	lib/security ${EGDIR}

do-install:
	${INSTALL} ${WRKSRC}/pam_tacplus.so ${DESTDIR}${PREFIX}/lib/security/
	${INSTALL} ${WRKSRC}/sample.pam ${DESTDIR}${EGDIR}/sample.pam

.include "../../mk/bsd.pkg.mk"
