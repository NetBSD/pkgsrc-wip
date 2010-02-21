# $NetBSD: Makefile,v 1.7 2010/02/21 21:27:46 cheusov Exp $

# this should use a Makefile.common to share the DISTNAME
DISTNAME=	gnats-3.113.1
PKGNAME=	send-pr-${GNATS_VERSION}
PKGREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNU=gnats/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/gnats/
COMMENT=	GNATS problem reporting tool

WRKSRC=		${WRKDIR}/gnats-${GNATS_VERSION}/send-pr
GNATS_VERSION=	${DISTNAME:S/gnats-//}

CONFLICTS+=	gnats-[0-9]*

GNU_CONFIGURE=		YES
PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		makeinfo
INFO_FILES=		yes

CONFIGURE_ARGS=		--with-lispdir=${PREFIX}/share/emacs/site-lisp
INSTALL_TARGET=		install install-info

# this stops the configuration program from pulling installation
# information in from the standard NetBSD send-pr program
CONFIGURE_ENV+=		SEND_PR=/dev/null

AUTO_MKDIRS=		yes

SUBST_CLASSES+=		fix-paths
SUBST_STAGE.fix-paths=	post-patch
SUBST_MESSAGE.fix-paths=Fixing paths
SUBST_FILES.fix-paths=	send-pr.sh
SUBST_SED.fix-paths=	-e 's,install-sid,${PREFIX}/bin/install-sid,'
SUBST_SED.fix-paths+=	-e 's,send-pr --request-id,${PREFIX}/bin/send-pr --request-id,'

post-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} info

post-install:
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DESTDIR}${PREFIX}/share/gnats/dist/INSTALL.send-pr
	${INSTALL_DATA} ${FILESDIR}/netbsd-categories ${DESTDIR}${PREFIX}/share/gnats/netbsd

.include "../../mk/bsd.pkg.mk"
