# $NetBSD: Makefile,v 1.33 2014/02/02 17:04:40 cheusov Exp $
#

DISTNAME=	mk-configure-0.26.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mk-configure/} \
		http://mova.org/~cheusov/pub/mk-configure/

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/mk-configure
COMMENT=	Lightweight but powerful replacement for GNU autotools
LICENSE=	modified-bsd

DEPENDS+=	bmake-[0-9]*:../../devel/bmake

GIT_REPOSITORIES=		mk-configure
GIT_REPO.mk-configure=	git://github.com/cheusov/mk-configure.git
.include "../../wip/mk/git-package.mk"

USE_LANGUAGES=		c

BUILD_TARGET=		all all-doc
INSTALL_TARGET=		install install-doc

WRKSRC=			${WRKDIR}/mk-configure
MAKE_PROGRAM=		${PREFIX}/bin/bmake

MAKE_ENV+=		MANDIR=${PREFIX}/${PKGMANDIR} \
			SYSCONFDIR=${PKG_SYSCONFDIR} \
			BMAKE=${PREFIX}/bin/bmake

AUTO_MKDIRS=		yes

EGDIR=			share/examples/mk-configure

TEST_TARGET=		test

post-install:
	cp -Rp ${WRKSRC}/examples/* ${DESTDIR}${PREFIX}/${EGDIR}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == SunOS && exists(/usr/xpg4/bin/awk)
REPLACE_INTERPRETER+=	awk
REPLACE.awk.old=	/usr/bin/awk
REPLACE.awk.new=	/usr/xpg4/bin/awk
REPLACE_FILES.awk=	mkc_check_version
.endif

.if ${OPSYS} != NetBSD && ${OPSYS} != FreeBSD && ${OPSYS} != OpenBSD && ${OPSYS} != DragonFly && ${OPSYS} != MirBSD
DEPENDS+=	bmkdep-[0-9]*:../../devel/bmkdep
.endif

.include "../../mk/bsd.pkg.mk"
