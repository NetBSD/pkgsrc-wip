# $NetBSD: Makefile,v 1.1.1.1 2011/01/07 16:56:46 pdtafti Exp $
#

DISTNAME=	LADR-2009-11A
PKGNAME=	prover9-2009-11A
CATEGORIES=	local math
MASTER_SITES=	http://www.cs.unm.edu/~mccune/prover9/download/

MAINTAINER=	pouya@san-serriffe.org
HOMEPAGE=	http://www.cs.unm.edu/~mccune/prover9/
COMMENT=	Prover9 is an automated theorem prover
LICENSE=	gnu-gpl-v2

USE_TOOLS+=				cp mv rm
MAKE_JOBS_SAFE=        	NO

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS=      bin ${PKGMANDIR}/man1 share/examples/prover9/prover9 share/examples/prover9/mace4

REPLACE_PYTHON=			utilities/attack utilities/gvizify utilities/looper utilities/prover9-mace4

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/* ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/prover9.examples/* ${DESTDIR}${PREFIX}/share/examples/prover9/prover9
	${INSTALL_DATA} ${WRKSRC}/mace4.examples/* ${DESTDIR}${PREFIX}/share/examples/prover9/mace4
	${INSTALL_MAN} ${WRKSRC}/manpages/* ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1


.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
