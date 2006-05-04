# $NetBSD: Makefile,v 1.1 2006/05/04 20:31:53 anielski Exp $

.include "Makefile.common"

COMMENT=		Modern, advanced and high performance nameserver

CONFIGURE_ARGS+=	--with-modules="" --with-dynmodules=""
RCD_SCRIPTS=		pdns
#LDFLAGS+=		-lrt
CONF_FILES+=    	${PREFIX}/etc/pdns.conf-dist \
                	${PREFIX}/etc/pdns.conf

.include "../../mk/bsd.pkg.mk"
