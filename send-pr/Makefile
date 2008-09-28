# $NetBSD: Makefile,v 1.5 2008/09/28 14:25:56 cheusov Exp $

# this should use a Makefile.common to share the DISTNAME
GNATS_VERSION=	3.113.1
DISTNAME=	gnats-${GNATS_VERSION}
PKGNAME=	send-pr-${GNATS_VERSION}
WRKSRC=		${WRKDIR}/gnats-${GNATS_VERSION}/send-pr
PKGREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNU=gnats/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/gnats/
COMMENT=	GNATS problem reporting tool

CONFLICTS+=	gnats-[0-9]*

GNU_CONFIGURE=		YES
PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		makeinfo
INFO_FILES=		# PLIST

CONFIGURE_ARGS=		--with-lispdir=${PREFIX}/share/emacs/site-lisp
INSTALL_TARGET=		install install-info

# this stops the configuration program from pulling installation
# information in from the standard NetBSD send-pr program
CONFIGURE_ENV+=	SEND_PR=/dev/null

AUTO_MKDIRS=	yes

post-patch:
	${SED} -e "s,install-sid,${PREFIX}/bin/install-sid," \
	  -e "s,send-pr --request-id,${PREFIX}/bin/send-pr --request-id," \
	  ${WRKSRC}/send-pr.sh > ${WRKSRC}/send-pr.sh.fixed && \
	${MV} ${WRKSRC}/send-pr.sh.fixed ${WRKSRC}/send-pr.sh

post-build:
	(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} info)

post-install:
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DESTDIR}${PREFIX}/share/gnats/dist/INSTALL.send-pr
	${INSTALL_DATA} ${FILESDIR}/netbsd-categories ${DESTDIR}${PREFIX}/share/gnats/netbsd

.include "../../mk/bsd.pkg.mk"
