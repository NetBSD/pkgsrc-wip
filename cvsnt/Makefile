# $NetBSD: Makefile,v 1.6 2012/09/24 18:26:56 asau Exp $
#

DISTNAME=	cvsnt-2.5.03.2382
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://www.cvsnt.org/archive/

MAINTAINER=	pkgsrc@blackmouse.biz
HOMEPAGE=	http://www.cvsnt.org/
COMMENT=	CVSNT is advanced multiplatform version control system

CONFLICTS=	cvs-[0-9]*


GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES=	c c++

CONFIGURE_ARGS+=		--without-gssapi

RCD_SCRIPTS+=		cvslockd

EGDIR=			${PREFIX}/share/examples/cvsnt
CONF_FILES=		${EGDIR}/ca.pem.example ${PKG_SYSCONFDIR}/cvsnt/ca.pem
CONF_FILES=		${EGDIR}/Plugins.example ${PKG_SYSCONFDIR}/cvsnt/Plugins
CONF_FILES=		${EGDIR}/PServer.example ${PKG_SYSCONFDIR}/cvsnt/PServer

CHECK_PORTABILITY_SKIP+=	pcre/configure

.include "options.mk"

.include "../../devel/libltdl/convenience.mk"
.include "../../devel/libntlm/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
