# $NetBSD: Makefile,v 1.2 2011/07/05 21:27:38 bubuchka Exp $
#

DISTNAME=	p4
HOMEPAGE=	http://www.perforce.com/perforce/products/p4.html
COMMENT=	Perforce SCM command-line client

PKG_DESTDIR_SUPPORT=	user-destdir

P4BINONLY=	yes

.include "../../wip/p4/Makefile.common"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME} \
		${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
