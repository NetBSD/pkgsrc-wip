# $NetBSD: Makefile,v 1.7 2013/04/14 20:05:24 shattered Exp $
#

DISTNAME=	cpm
PKGNAME=	cpm-0.22rc1
PKGREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://www.harry-b.de/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.harry-b.de/dokuwiki/doku.php?id=harry:cpm
COMMENT=	Console Password Manager
LICENSE=	gnu-gpl-v2

WRKSRC=			${WRKDIR}/cpm-0.22beta
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-crack-dict=${PREFIX}/libdata/pw_dict
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		perl gmake
CPPFLAGS+=		-DPKG_SYSCONFDIR="\"${PKG_SYSCONFDIR}\""

EGDIR=			share/examples/cpm
CONF_FILES=		${EGDIR}/cpmrc ${PKG_SYSCONFDIR}/cpmrc
INSTALLATION_DIRS+=	bin ${EGDIR} share/locale/de/LC_MESSAGES ${PKGMANDIR}/man1

post-install:
	${INSTALL_DATA} ${WRKSRC}/conf/cpmrc-default ${DESTDIR}${PREFIX}/${EGDIR}/cpmrc

.include "../../devel/cdk/buildlink3.mk"
.include "../../devel/dotconf/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.include "../../security/libcrack/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
