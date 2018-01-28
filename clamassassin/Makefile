# $NetBSD: Makefile,v 1.10 2012/09/24 18:26:54 asau Exp $

DISTNAME=	clamassassin-1.2.2
CATEGORIES=	mail
MASTER_SITES=	http://jameslick.com/clamassassin/

MAINTAINER=	ura@jp.NetBSD.org
HOMEPAGE=	http://jameslick.com/clamassassin/
COMMENT=	Simple virus filter wrapper for ClamAV

DEPENDS+=	clamav>=0.84:../../security/clamav
DEPENDS+=	procmail>=3.22nb1:../../mail/procmail


GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CONF_RM=${RM:Q}
CONFIGURE_ENV+=	CONF_CAT=${CAT:Q}
CONFIGURE_ENV+=	CONF_SED=${SED:Q}
CONFIGURE_ENV+=	CONF_ECHO=${TOOLS_ECHO}

PKG_OPTIONS_VAR=	PKG_OPTIONS.clamassassin
PKG_SUPPORTED_OPTIONS=	clamdscan subject_rewrite
PKG_SUGGESTED_OPTIONS=	clamdscan

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mclamdscan)
CONFIGURE_ARGS+=	--enable-clamdscan
.endif

.if !empty(PKG_OPTIONS:Msubject_rewrite)
.  if empty(CLAMASSASSIN_SUBJECT_REWRITE)
CONFIGURE_ARGS+=	--enable-subject-rewrite
.  else
CONFIGURE_ARGS+=	--enable-subject-rewrite=${CLAMASSASSIN_SUBJECT_REWRITE:Q}
.  endif
.endif

.include "../../mk/bsd.pkg.mk"
