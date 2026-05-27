
// Generated from grammar/PythonRustParser.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "PythonRustParserVisitor.h"


/**
 * This class provides an empty implementation of PythonRustParserVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  PythonRustParserBaseVisitor : public PythonRustParserVisitor {
public:

  virtual std::any visitProgram(PythonRustParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStmt(PythonRustParser::StmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimple_stmt(PythonRustParser::Simple_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSmall_stmt(PythonRustParser::Small_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpr_stmt(PythonRustParser::Expr_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAnnassign(PythonRustParser::AnnassignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReturn_stmt(PythonRustParser::Return_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitImport_stmt(PythonRustParser::Import_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitImport_list(PythonRustParser::Import_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDotted_name(PythonRustParser::Dotted_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRaise_stmt(PythonRustParser::Raise_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPass_stmt(PythonRustParser::Pass_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFlow_stmt(PythonRustParser::Flow_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCompound_stmt(PythonRustParser::Compound_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIf_stmt(PythonRustParser::If_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWhile_stmt(PythonRustParser::While_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFor_stmt(PythonRustParser::For_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTry_stmt(PythonRustParser::Try_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExcept_clause(PythonRustParser::Except_clauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncdef(PythonRustParser::FuncdefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitClassdef(PythonRustParser::ClassdefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSuite(PythonRustParser::SuiteContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParameters(PythonRustParser::ParametersContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParam(PythonRustParser::ParamContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArglist(PythonRustParser::ArglistContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitKwArg(PythonRustParser::KwArgContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPosArg(PythonRustParser::PosArgContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTarget_list(PythonRustParser::Target_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTarget(PythonRustParser::TargetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTestlist(PythonRustParser::TestlistContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType(PythonRustParser::TypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAndExpr(PythonRustParser::AndExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMulDivExpr(PythonRustParser::MulDivExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMemberExpr(PythonRustParser::MemberExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCompExpr(PythonRustParser::CompExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCallExpr(PythonRustParser::CallExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNotExpr(PythonRustParser::NotExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAtomExpr(PythonRustParser::AtomExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnaryExpr(PythonRustParser::UnaryExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAddSubExpr(PythonRustParser::AddSubExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOrExpr(PythonRustParser::OrExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIndexExpr(PythonRustParser::IndexExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSubscript(PythonRustParser::SubscriptContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSlice(PythonRustParser::SliceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIntAtom(PythonRustParser::IntAtomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFloatAtom(PythonRustParser::FloatAtomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStringAtom(PythonRustParser::StringAtomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTrueAtom(PythonRustParser::TrueAtomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFalseAtom(PythonRustParser::FalseAtomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNoneAtom(PythonRustParser::NoneAtomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIdAtom(PythonRustParser::IdAtomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitListAtom(PythonRustParser::ListAtomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSetDictAtom(PythonRustParser::SetDictAtomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGroupOrTupleAtom(PythonRustParser::GroupOrTupleAtomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitList_maker(PythonRustParser::List_makerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSet_or_dict(PythonRustParser::Set_or_dictContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDict_kv(PythonRustParser::Dict_kvContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitComp_clause(PythonRustParser::Comp_clauseContext *ctx) override {
    return visitChildren(ctx);
  }


};

