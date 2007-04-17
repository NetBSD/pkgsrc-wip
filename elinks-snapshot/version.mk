# $NetBSD: version.mk,v 1.3 2007/04/17 20:24:48 bsadewitz Exp $

ELINKS_DATE_CMD=	${DATE} +%Y%m%d
ELINKS_VERSION!=	${ELINKS_DATE_CMD}
