# $NetBSD: Makefile,v 1.1.1.1 2005/06/02 07:49:29 ura Exp $
# FreeBSD Id: ports/security/clamassassin/Makefile,v 1.3 2004/10/21 15:18:58 leeym Exp

DISTNAME=	clamassassin-1.2.2
CATEGORIES=	mail
MASTER_SITES=	http://drivel.com/clamassassin/

MAINTAINER=	ura@jp.NetBSD.org
HOMEPAGE=	http://drivel.com/clamassassin/
COMMENT=	Simple virus filter wrapper for ClamAV

DEPENDS+=	clamav>=0.84:../../mail/clamav

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CONF_RM=/bin/rm
CONFIGURE_ENV+=	CONF_CAT=/bin/cat
CONFIGURE_ENV+=	CONF_SED=/usr/bin/sed
CONFIGURE_ENV+=	CONF_ECHO=/bin/echo

PKG_OPTIONS_VAR=	PKG_OPTIONS.clamassassin
PKG_SUPPORTED_OPTIONS=  clamdscan subject_rewrite
PKG_SUGGESTED_OPTIONS=  clamdscan

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mclamdscan)
CONFIGURE_ARGS+=	--enable-clamdscan
.endif

.if !empty(PKG_OPTIONS:Msubject_rewrite)
DEPENDS+=		procmail>=3.22nb1:../../mail/procmail
.if empty(CLAMASSASSIN_SUBJECT_REWRITE)
CONFIGURE_ARGS+=	--enable-subject-rewrite
.else
CONFIGURE_ARGS+=	--enable-subject-rewrite=${CLAMASSASSIN_SUBJECT_REWRITE}
.endif
.endif

.include "../../mk/bsd.pkg.mk"
