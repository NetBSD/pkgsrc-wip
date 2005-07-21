# $NetBSD: Makefile,v 1.5 2005/07/21 16:34:08 thomasklausner Exp $

.include "Makefile.common"

COMMENT=	GTK-based implementation of the wxWidgets GUI library

LIBWXREGEX=	${WRKSRC}/lib/libwxregex${UNICODE}.a

post-install:
	@-${INSTALL_DATA} ${LIBWXREGEX} ${PREFIX}/lib

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/pkg-config/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
