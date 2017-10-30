# $NetBSD$

DISTNAME=	charybdis-4.0
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=charybdis-ircd/}
GITHUB_TAG=	${DISTNAME}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/freenode/ircd-seven/
COMMENT=	Freenode's IRC server daemon
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	automake autoconf autoreconf

GNU_CONFIGURE=	yes

INSTALL_MAKE_FLAGS+=	sysconfdir=${PREFIX}/share/examples/charybdis

pre-configure:
	${RUN} cd ${WRKSRC} && ./autogen.sh

MAKE_DIRS+=	${PKG_SYSCONFDIR}
.for f in ircd.conf.example ircd.motd reference.conf
CONF_FILES+=	${PREFIX}/share/examples/charybdis/${f} \
		${PKG_SYSCONFDIR}/${f}
.endfor

.include "../../mk/bsd.pkg.mk"
