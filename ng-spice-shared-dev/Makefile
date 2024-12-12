# $NetBSD: Makefile,v 1.1 2023/06/06 09:56:08 bouyer Exp $

.include "../../wip/ng-spice-dev/Makefile.common"

PKGNAME=	ng-spice-shared-${VERSION}
#PKGREVISION=	1
COMMENT=	Next generation circuit simulation program (shared libraries)

CONFIGURE_ARGS+=	--with-ngshared=YES

post-install:
	${RM} -r ${DESTDIR}${PREFIX}/share/ngspice/scripts ${DESTDIR}${PREFIX}/lib/ngspice

.include "../../math/fftw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
