# $NetBSD: Makefile,v 1.6 2010/03/12 09:55:22 thomasklausner Exp $
#

DISTNAME=	pam_tacplus-1.2.11
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tacplus/}

MAINTAINER=	pettai@nordu.net
HOMEPAGE=	http://tacplus.sourceforge.net/
COMMENT=	TACACS+ client library and PAM module
#LICENSE=

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/tacplus
EGDIR=			${PREFIX}/share/examples/pam_tacplus
DOCDIR=			${PREFIX}/share/doc/pam_tacplus

SUBST_CLASSES+=         paths
SUBST_FILES.paths=      ${WRKSRC}/Makefile
SUBST_STAGE.paths=      post-patch
SUBST_SED.paths=        -e 's,@PREFIX@,${PREFIX},'

INSTALLATION_DIRS=	lib/security ${EGDIR} ${DOCDIR}

do-install:
	${INSTALL} ${WRKSRC}/pam_tacplus.so \
			${DESTDIR}${PREFIX}/lib/security/pam_tacplus.so
	${INSTALL} ${WRKSRC}/README \
			${DESTDIR}${DOCDIR}/README
	${INSTALL} ${WRKSRC}/sample.pam \
			${DESTDIR}${EGDIR}/sample.pam

.include "../../mk/bsd.pkg.mk"
