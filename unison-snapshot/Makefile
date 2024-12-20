# $NetBSD: Makefile,v 1.166 2024/11/23 13:59:40 wiz Exp $

# master after 2.53.7
DISTNAME=	unison-2.53.7.51
#PKGREVISION=	0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=bcpierce00/}
GITHUB_TAG=	8db0681d52140512f6154cac01596b276415ad13

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://github.com/bcpierce00/unison
#HOMEPAGE+=	https://www.cis.upenn.edu/~bcpierce/unison/
COMMENT=	File-synchronization tool
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	bash
# \todo Explain
MAKE_FLAGS+=	CFLAGS=""
ALL_ENV+=	PREFIX=${PREFIX}
ALL_ENV+=	MANDIR=${PREFIX}/${PKGMANDIR}
MAKE_ENV+=	HOME=${WRKDIR:Q}

.include "../../lang/ocaml/ocaml.mk"

# Unison will use ocamlopt if possible, and otherwise ocamlc, but
# passing NATIVE lets pkgsrc build byte code on a native platform,
# should that be desired.
.if ${OCAML_USE_OPT_COMPILER} == "yes"
MAKE_FLAGS+=	NATIVE=true
.else
MAKE_FLAGS+=	NATIVE=false
.endif

# bsd.prefs.mk, included also by options, must be after ocaml to get
# _PKGSRC_MKPIE set correctly.
.include "options.mk"
.include "../../mk/bsd.prefs.mk"

# \todo
#   add fsmonitor option, needing python and libinotify, or forcing it off
#   for now, it is statically forced off, pending upstream fix

# Unison does not install non-man docs
INSTALLATION_DIRS+=	share/doc/unison

post-install:
	${INSTALL_MAN} ${WRKSRC}/src/COPYING ${DESTDIR}${PREFIX}/share/doc/unison
	${INSTALL_MAN} ${WRKSRC}/CONTRIBUTING.md ${DESTDIR}${PREFIX}/share/doc/unison
	${INSTALL_MAN} ${WRKSRC}/INSTALL.md ${DESTDIR}${PREFIX}/share/doc/unison
	${INSTALL_MAN} ${WRKSRC}/NEWS.md ${DESTDIR}${PREFIX}/share/doc/unison
	# \todo See fsmonitor above.
	${RM} ${DESTDIR}${PREFIX}/bin/fsmonitor.py

TEST_TARGET=		test

.include "../../mk/pthread.buildlink3.mk"
.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} != "none")
MAKE_FLAGS+=	THREADS=true
.endif

.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
