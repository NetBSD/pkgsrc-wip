# $NetBSD: Makefile,v 1.4 2004/03/26 23:26:55 marc Exp $

.include "Makefile.common"

COMMENT=	GTK-based implementation of the wxWidgets GUI library

LIBWXREGEX=	${WRKSRC}/lib/libwxregex${UNICODE}.a

post-install:
	@-${INSTALL_DATA} ${LIBWXREGEX} ${PREFIX}/lib

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
