# $NetBSD: Makefile,v 1.7 2004/05/09 04:08:37 blef Exp $
# based on FreeBSD-port pkgtrace originally by ijliao
# created 2003-10-22 Patrick Atamaniuk <atamaniuk-pkgsrc@frobs.net>

DISTNAME=	mftrace-1.0.19
CATEGORIES=	fonts
MASTER_SITES=	http://www.xs4all.nl/~hanwen/mftrace/

MAINTAINER=	atamaniuk-pkgsrc@frobs.net
HOMEPAGE=	http://www.xs4all.nl/~hanwen/mftrace/
COMMENT=	Scalable PostScript (Type1) Fonts for MetaFont

DEPENDS+=	teTeX>=2.0.2:../../print/teTeX
DEPENDS+=	autotrace>=0.31:../../graphics/autotrace
DEPENDS+=	t1utils>=1.27:../../fonts/t1utils
DEPENDS+=	pfaedit>=20030712:../../fonts/pfaedit

USE_BUILDLINK3=	yes
GNU_CONFIGURE=	yes
USE_GNU_TOOLS+=	make
MAKEFILE=	GNUmakefile

CONFIGURE_ARGS+=	--build=${MACHINE_ARCH}-portbld-netbsd${OSREL}
CONFIGURE_ENV+= PYTHON=${PYTHONBIN}

PYTHON_VERSIONS_ACCEPTED= 20 21 21pth 22 22pth 23 23pth
PY_PATCHPLIST=  YES
PLIST_SUBST+=   PYINC=${PYINC} PYSITELIB=${PYSITELIB}

MANPREFIX?=	${PREFIX}

do-install:
	echo "Installing mftrace"
	${INSTALL_PROGRAM} ${WRKSRC}/gf2pbm ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/mftrace ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/mftrace.1 ${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/tfm.py ${PREFIX}/${PYSITELIB}
	${INSTALL_DATA} ${WRKSRC}/afm.py ${PREFIX}/${PYSITELIB}

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
