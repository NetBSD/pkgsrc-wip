# $NetBSD: Makefile,v 1.3 2010/11/15 18:37:33 shattered Exp $
#

DISTNAME=	cpm
PKGNAME=	cpm-0.22rc1
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.harry-b.de/downloads/

MAINTAINER=	shattered@users.sourceforge.net
HOMEPAGE=	http://www.harry-b.de/dokuwiki/doku.php?id=harry:cpm
COMMENT=	Console Password Manager

WRKSRC=			${WRKDIR}/cpm-0.22beta
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-crack-dict=${PREFIX}/libdata/pw_dict
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		perl gmake
CPPFLAGS+=		-DPKG_SYSCONFDIR="\"${PKG_SYSCONFDIR}\""

EGDIR=			${PREFIX}/share/examples/cpm
CONF_FILES=		${EGDIR}/cpmrc ${PKG_SYSCONFDIR}/cpmrc
INSTALLATION_DIRS+=	${EGDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/conf/cpmrc-default ${EGDIR}/cpmrc

.include "../../devel/cdk/buildlink3.mk"
.include "../../devel/dotconf/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.include "../../security/libcrack/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
