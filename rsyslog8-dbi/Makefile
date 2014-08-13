# $NetBSD: Makefile,v 1.1 2014/08/13 10:51:04 fhajny Exp $
#

RSYSLOG_MOD=	dbi
PKGNAME=	${DISTNAME:S/rsyslog/rsyslog-${RSYSLOG_MOD}/}

DEPENDS+=	rsyslog>=${PKGVERSION_NOREV}:../../wip/rsyslog8

.include "../../wip/rsyslog8/Makefile.common"

CONFIGURE_ARGS+=	--enable-libdbi

BUILD_DIRS=		plugins/omlibdbi

.include "../../databases/libdbi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
