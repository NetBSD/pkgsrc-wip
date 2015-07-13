# $NetBSD: Makefile,v 1.1 2015/07/13 18:54:04 leot1990 Exp $

DISTNAME=	fio-2.2.9
CATEGORIES=	benchmarks
MASTER_SITES=	http://brick.kernel.dk/snaps/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://git.kernel.dk/?p=fio.git;a=summary
COMMENT=	Flexible IO Tester
LICENSE=	gnu-gpl-v2

HAS_CONFIGURE=	yes
USE_TOOLS+=	bash gmake lex yacc

DOCDIR=		${PREFIX}/share/doc/fio
EGDIR=		${PREFIX}/share/example/fio

SUBST_CLASSES+=		makefile
SUBST_STAGE.makefile=	pre-build
SUBST_MESSAGE.makefile=	Fixing paths in Makefile
SUBST_FILES.makefile=	Makefile
SUBST_SED.makefile=	-E -e 's,^(prefix =).*,\1 ${PREFIX},'
SUBST_SED.makefile+=	-E -e 's,^(mandir =).*,\1 ${PREFIX}/${PKGMANDIR},'
SUBST_SED.makefile+=	-E -e 's,^(sharedir =).*,\1 ${PREFIX}/share/fio,'

REPLACE_BASH+=		tools/genfio
REPLACE_PYTHON+=	tools/plot/fio2gnuplot

INSTALLATION_DIRS=	${DOCDIR} ${EGDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/HOWTO ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.fio ${DESTDIR}${EGDIR}

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
