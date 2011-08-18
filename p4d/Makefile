# $NetBSD: Makefile,v 1.1.1.1 2011/08/18 20:51:01 bubuchka Exp $
#

DISTNAME=	p4d
HOMEPAGE=	http://www.perforce.com/product/components/perforce_server
COMMENT=	Perforce SCM server

PKG_DESTDIR_SUPPORT=	user-destdir

P4BINONLY=	yes
EXTRACT_ONLY=	# none

.include "../../wip/p4/Makefile.common"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME} \
		${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
