# $NetBSD: Makefile,v 1.163 2021/09/12 09:15:10 wiz Exp $

DISTNAME=	wget2-2.0.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GNU:=wget/}
EXTRACT_SUFX=	.tar.lz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.com/gnuwget/wget2
COMMENT=	Successor to wget with more modern features
LICENSE=	gnu-lgpl-v3

#USE_TOOLS+=		perl pod2man pkg-config

GNU_CONFIGURE=		YES
#USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		msgfmt

#CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

#REPLACE_PERL+=		doc/texi2pod.pl

#EGDIR=			${PREFIX}/share/examples/wget
#CONF_FILES=		${EGDIR}/wgetrc ${PKG_SYSCONFDIR}/wgetrc
#INFO_FILES=		YES

#INSTALL_MAKE_FLAGS=	${MAKE_FLAGS} sysconfdir=${EGDIR}

.include "options.mk"

.include "../../devel/zlib/buildlink3.mk"
#.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
