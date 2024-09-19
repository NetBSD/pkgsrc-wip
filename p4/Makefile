# $NetBSD: Makefile,v 1.5 2012/10/04 09:13:18 asau Exp $
#

DISTNAME=	p4
HOMEPAGE=	http://www.perforce.com/product/components/perforce_commandline_client
COMMENT=	Perforce SCM command-line client

P4BINONLY=	yes
EXTRACT_ONLY=	# none

.include "../../wip/p4/Makefile.common"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME} \
		${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
