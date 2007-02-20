# $NetBSD: Makefile,v 1.1.1.1 2007/02/20 19:59:08 briandealwis Exp $
#

DISTNAME=		mime-support_3.9-1.3
PKGNAME=		mime-support-3.9
MASTER_SITES=		http://security.debian.org/pool/updates/main/m/mime-support/
CATEGORIES=		mail

MAINTAINER=		bsd@cs.ubc.ca
COMMENT=		Support commands for manipulating files using MIME and mailcap

USE_TOOLS+=		perl:run
WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
NO_BUILD=		yes

REPLACE_PERL+=		run-mailcap

SUBST_CLASSES+=		fix-paths
SUBST_MESSAGE.fix-paths=Fixing path references
SUBST_STAGE.fix-paths=	pre-configure
SUBST_FILES.fix-paths=	run-mailcap.man
SUBST_SED.fix-paths=	-e 's,@PREFIX@,${PREFIX},g'

SUBST_CLASSES+=		fix-x11
SUBST_MESSAGE.fix-x11=	Fixing X11 references
SUBST_STAGE.fix-x11=	pre-configure
SUBST_FILES.fix-x11=	run-mailcap
SUBST_SED.fix-x11=	-e 's,/usr/bin/X11,${X11BASE},g'

# Note: the mime-support provides other commands for managing /etc/mailcap:
#    but they're not necessary with pkgsrc and hence are ignored.
do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/run-mailcap ${PREFIX}/bin
	cd ${PREFIX}/bin; ${LN} run-mailcap mime-edit
	cd ${PREFIX}/bin; ${LN} run-mailcap mime-compose
	cd ${PREFIX}/bin; ${LN} run-mailcap mime-see
	cd ${PREFIX}/bin; ${LN} run-mailcap mime-print
	${INSTALL_MAN} ${WRKSRC}/run-mailcap.man ${PREFIX}/${PKGMANDIR}/man1/run-mailcap.1

.include "../../mk/bsd.pkg.mk"
