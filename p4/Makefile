# $NetBSD: Makefile,v 1.4 2011/08/18 21:00:35 bubuchka Exp $
#

DISTNAME=	p4
HOMEPAGE=	http://www.perforce.com/product/components/perforce_commandline_client
COMMENT=	Perforce SCM command-line client

PKG_DESTDIR_SUPPORT=	user-destdir

P4BINONLY=	yes
EXTRACT_ONLY=	# none

.include "../../wip/p4/Makefile.common"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME} \
		${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
