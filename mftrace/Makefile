# $NetBSD: Makefile,v 1.3 2003/10/26 10:06:11 atamaniuk Exp $
# based on FreeBSD-port pkgtrace originally by ijliao
# created 2003-10-22 Patrick Atamaniuk <atamaniuk-pkgsrc@frobs.net>

DISTNAME=	mftrace-1.0.19
CATEGORIES=	fonts
MASTER_SITES=	http://www.xs4all.nl/~hanwen/mftrace/

MAINTAINER=	atamaniuk-pkgsrc@frobs.net
HOMEPAGE=	http://www.xs4all.nl/~hanwen/mftrace/
COMMENT=	Scalable PostScript (Type1) Fonts for MetaFont

DEPENDS+=	teTeX2>=2.0.2:../../print/teTeX2
DEPENDS+=	autotrace>=0.31:../../graphics/autotrace
DEPENDS+=	t1utils>=1.27:../../fonts/t1utils
DEPENDS+=	pfaedit>=20030712:../../fonts/pfaedit

USE_BUILDLINK2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
MAKEFILE=	GNUmakefile

CONFIGURE_ARGS+=	--build=${MACHINE_ARCH}-portbld-netbsd${OSREL}
CONFIGURE_ENV+= PYTHON=${PYTHONBIN}

PYTHON_VERSIONS_ACCEPTED= 20 21 23 # 22 has some regular expression problem
PY_PATCHPLIST=  YES
PLIST_SUBST+=   PYINC=${PYINC} PYSITELIB=${PYSITELIB}

MANPREFIX?=	${PREFIX}

post-install:
	${ECHO} "import sys" > ${WRKSRC}/compile.py
	${ECHO} "sys.path.insert(0,\"${PREFIX}/${PYSITELIB}\")" >> ${WRKSRC}/compile.py
	${ECHO} "print sys.path" >> ${WRKSRC}/compile.py
	${ECHO} "import afm" >> ${WRKSRC}/compile.py
	${ECHO} "import tfm" >> ${WRKSRC}/compile.py
	${PYTHONBIN} ${WRKSRC}/compile.py

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gf2pbm ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/mftrace ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/mftrace.1 ${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/tfm.py ${PREFIX}/${PYSITELIB}
	${INSTALL_DATA} ${WRKSRC}/afm.py ${PREFIX}/${PYSITELIB}

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
